import os
import sys
import re
import json
import smtplib
from pathlib import Path
from datetime import datetime
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

# --- PATH CONFIGURATION ---
BASE_DIR = Path(__file__).resolve().parent.parent
ENV_FILE = BASE_DIR / ".env"
README_FILE = BASE_DIR / "README.md"
PREVIEW_FILE = BASE_DIR / "preview.html"

# Load .env file manually (zero dependencies)
def load_env():
    env_vars = {}
    if ENV_FILE.exists():
        with open(ENV_FILE, "r", encoding="utf-8") as f:
            for line in f:
                line = line.strip()
                if line and not line.startswith("#") and "=" in line:
                    key, value = line.split("=", 1)
                    env_vars[key.strip()] = value.strip().strip('"').strip("'")
    return env_vars

ENV = load_env()

# Get env variables with fallback to os.environ
GMAIL_USER = ENV.get("GMAIL_USER") or os.environ.get("GMAIL_USER", "")
GMAIL_APP_PASSWORD = ENV.get("GMAIL_APP_PASSWORD") or os.environ.get("GMAIL_APP_PASSWORD", "")
RECIPIENT_EMAIL = ENV.get("RECIPIENT_EMAIL") or os.environ.get("RECIPIENT_EMAIL") or GMAIL_USER

# --- SKILL DISCOVERY & STATS PARSER ---
def parse_learning_data():
    skills = []
    
    # Check for skill directories with progress.md or syllabus.md
    for item in BASE_DIR.iterdir():
        if item.is_dir() and not item.name.startswith((".", "scripts", "dashboard")):
            progress_file = item / "progress.md"
            syllabus_file = item / "syllabus.md"
            
            if progress_file.exists() or syllabus_file.exists():
                level = 1
                tier = "Tier 1 (Beginner)"
                status = "In Progress"
                
                if progress_file.exists():
                    content = progress_file.read_text(encoding="utf-8")
                    lvl_match = re.search(r"Current Level:\s*(\d+)", content, re.IGNORECASE)
                    if lvl_match:
                        level = int(lvl_match.group(1))
                    
                    tier_match = re.search(r"Tier:\s*(.+)", content, re.IGNORECASE)
                    if tier_match:
                        tier = tier_match.group(1).strip()
                
                skills.append({
                    "name": item.name,
                    "level": level,
                    "tier": tier,
                    "status": status,
                    "progress_pct": min(100, max(1, level))
                })

    total_level = sum(s["level"] for s in skills)
    avg_level = round(total_level / len(skills), 1) if skills else 0
    player_tier = get_player_tier(avg_level)

    return {
        "skills": skills,
        "total_skills": len(skills),
        "avg_level": avg_level,
        "total_level": total_level,
        "player_tier": player_tier,
        "date_str": datetime.now().strftime("%B %d, %Y")
    }

def get_player_tier(level):
    if level >= 81: return "👑 Master Polymath"
    if level >= 61: return "🔥 Advanced Engineer"
    if level >= 41: return "⚙️ Intermediate Specialist"
    if level >= 21: return "📖 Foundational Explorer"
    return "🌱 Novice Practitioner"

# --- HTML EMAIL TEMPLATE GENERATOR ---
def generate_email_html(data):
    skills = data["skills"]
    date_str = data["date_str"]
    avg_level = data["avg_level"]
    player_tier = data["player_tier"]
    
    # Skill cards generator
    skill_cards_html = ""
    if not skills:
        skill_cards_html = """
        <div style="background-color: #1e293b; border: 1px dashed #334155; border-radius: 12px; padding: 24px; text-align: center; color: #94a3b8;">
            <p style="margin: 0; font-size: 16px;">🚀 <strong>No skills active yet!</strong></p>
            <p style="margin: 8px 0 0 0; font-size: 14px; color: #64748b;">Tell your AI tutor which skill (DSA, C, AWS, Networking) you want to unlock first!</p>
        </div>
        """
    else:
        for skill in skills:
            pct = skill["progress_pct"]
            skill_cards_html += f"""
            <div style="background: #1e293b; border: 1px solid #334155; border-radius: 12px; padding: 18px 20px; margin-bottom: 14px;">
                <div style="display: flex; justify-content: space-between; align-items: center; margin-bottom: 8px;">
                    <span style="font-size: 16px; font-weight: 700; color: #f8fafc;">{skill['name']}</span>
                    <span style="font-size: 13px; font-weight: 600; color: #38bdf8; background: rgba(56, 189, 248, 0.1); padding: 4px 10px; border-radius: 20px;">Lvl {skill['level']} / 100</span>
                </div>
                <div style="background-color: #0f172a; border-radius: 8px; height: 10px; width: 100%; overflow: hidden; margin-bottom: 8px;">
                    <div style="background: linear-gradient(90deg, #38bdf8 0%, #818cf8 100%); width: {pct}%; height: 100%; border-radius: 8px;"></div>
                </div>
                <div style="display: flex; justify-content: space-between; font-size: 12px; color: #94a3b8;">
                    <span>{skill['tier']}</span>
                    <span>{pct}% Mastered</span>
                </div>
            </div>
            """

    return f"""<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Daily Learning Digest</title>
</head>
<body style="margin: 0; padding: 0; background-color: #0f172a; font-family: 'Segoe UI', -apple-system, BlinkMacSystemFont, Roboto, sans-serif; color: #f8fafc;">
    <div style="max-width: 600px; margin: 0 auto; padding: 20px;">
        
        <!-- HEADER -->
        <div style="background: linear-gradient(135deg, #1e1b4b 0%, #0f172a 100%); border: 1px solid #312e81; border-radius: 16px; padding: 28px 24px; text-align: center; margin-bottom: 20px; box-shadow: 0 10px 25px -5px rgba(0, 0, 0, 0.5);">
            <div style="font-size: 36px; margin-bottom: 8px;">⚡</div>
            <h1 style="margin: 0; font-size: 24px; font-weight: 800; color: #ffffff; letter-spacing: -0.5px;">Daily Learning Digest</h1>
            <p style="margin: 6px 0 0 0; font-size: 14px; color: #a5b4fc;">{date_str}</p>
        </div>

        <!-- STATS HERO CARD -->
        <div style="background: #1e293b; border: 1px solid #334155; border-radius: 16px; padding: 24px; margin-bottom: 20px;">
            <div style="display: table; width: 100%;">
                <div style="display: table-cell; width: 50%; text-align: center; border-right: 1px solid #334155; padding-right: 12px;">
                    <div style="font-size: 12px; text-transform: uppercase; letter-spacing: 1px; color: #94a3b8; font-weight: 600;">Overall Status</div>
                    <div style="font-size: 20px; font-weight: 800; color: #38bdf8; margin-top: 6px;">{player_tier}</div>
                </div>
                <div style="display: table-cell; width: 50%; text-align: center; padding-left: 12px;">
                    <div style="font-size: 12px; text-transform: uppercase; letter-spacing: 1px; color: #94a3b8; font-weight: 600;">Average Level</div>
                    <div style="font-size: 24px; font-weight: 800; color: #818cf8; margin-top: 4px;">Lvl {avg_level}</div>
                </div>
            </div>
        </div>

        <!-- ACTIVE SKILLS -->
        <div style="margin-bottom: 24px;">
            <h2 style="font-size: 16px; font-weight: 700; color: #cbd5e1; text-transform: uppercase; letter-spacing: 0.8px; margin: 0 0 14px 4px;">Skill Matrix</h2>
            {skill_cards_html}
        </div>

        <!-- MOTIVATION & ACTION -->
        <div style="background: linear-gradient(135deg, #065f46 0%, #064e3b 100%); border: 1px solid #047857; border-radius: 14px; padding: 20px; text-align: center; margin-bottom: 24px;">
            <p style="margin: 0; font-size: 15px; font-weight: 600; color: #ecfdf5;">"Consistency beats intensity. One focused lesson today pushes your level up tomorrow."</p>
            <div style="margin-top: 14px;">
                <span style="background-color: #10b981; color: #064e3b; font-size: 13px; font-weight: 800; padding: 8px 18px; border-radius: 20px; display: inline-block;">Ready to Level Up? 🚀</span>
            </div>
        </div>

        <!-- FOOTER -->
        <div style="text-align: center; font-size: 12px; color: #64748b; padding-top: 10px; border-top: 1px solid #1e293b;">
            <p style="margin: 0;">Learning Through AI — Personal Learning OS</p>
            <p style="margin: 4px 0 0 0;">Keep grinding, keep building.</p>
        </div>

    </div>
</body>
</html>
"""

# --- SEND EMAIL VIA GMAIL SMTP ---
def send_email(html_content, recipient):
    if not GMAIL_USER or not GMAIL_APP_PASSWORD:
        print("❌ Error: GMAIL_USER or GMAIL_APP_PASSWORD missing in .env file.")
        print("Please configure your credentials in .env first.")
        return False

    msg = MIMEMultipart("alternative")
    msg["Subject"] = f"⚡ Your Daily Learning Stats & Progress — {datetime.now().strftime('%b %d')}"
    msg["From"] = f"Learning OS <{GMAIL_USER}>"
    msg["To"] = recipient
    
    msg.attach(MIMEText(html_content, "html"))

    try:
        print(f"Connecting to Gmail SMTP server...")
        with smtplib.SMTP("smtp.gmail.com", 587) as server:
            server.starttls()
            server.login(GMAIL_USER, GMAIL_APP_PASSWORD)
            server.sendmail(GMAIL_USER, recipient, msg.as_string())
        print(f"✅ Daily digest email successfully sent to {recipient}!")
        return True
    except Exception as e:
        print(f"❌ Failed to send email: {e}")
        return False

# --- MAIN ENTRYPOINT ---
def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    data = parse_learning_data()
    html = generate_email_html(data)
    
    # Save preview HTML file
    with open(PREVIEW_FILE, "w", encoding="utf-8") as f:
        f.write(html)
    print(f"🖼️ Preview saved to: file:///{PREVIEW_FILE.as_posix()}")

    if "--send" in sys.argv:
        send_email(html, RECIPIENT_EMAIL)
    else:
        print("💡 Tip: Run `python scripts/send_daily_digest.py --send` to transmit the email via Gmail.")


if __name__ == "__main__":
    main()
