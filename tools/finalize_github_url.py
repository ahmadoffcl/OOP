"""
Update final submission files with the public GitHub URL.

Usage:
    python tools/finalize_github_url.py https://github.com/YOUR_USERNAME/HITEC-OOP-SCMS-25-CS-067
    python tools/finalize_github_url.py --dry-run https://github.com/YOUR_USERNAME/HITEC-OOP-SCMS-25-CS-067

This updates README.md and regenerates docs/project_report.pdf with the same URL.
"""

from pathlib import Path
import argparse
import re
import subprocess
import sys


ROOT = Path(__file__).resolve().parents[1]
README = ROOT / "README.md"
GENERATOR = ROOT / "tools" / "generate_deliverables.py"


def check_url(url):
    if not url.startswith("https://github.com/"):
        print("Error: URL must start with https://github.com/")
        return False

    if "HITEC-OOP-SCMS-25-CS-067" not in url:
        print("Error: URL should contain HITEC-OOP-SCMS-25-CS-067")
        return False

    return True


def update_readme(url):
    text = README.read_text(encoding="utf-8")
    pattern = r"https://github\.com/[^\s`]+/HITEC-OOP-SCMS-25-CS-067"

    if re.search(pattern, text):
        text = re.sub(pattern, url, text)
    else:
        text += f"\n\n## GitHub Repository\n\n```text\n{url}\n```\n"

    README.write_text(text, encoding="utf-8")


def regenerate_report(url):
    subprocess.check_call([
        sys.executable,
        str(GENERATOR),
        "--github-url",
        url,
    ], cwd=str(ROOT))


def main():
    parser = argparse.ArgumentParser(description="Update final SCMS files with GitHub URL.")
    parser.add_argument("url", help="Public GitHub repository URL")
    parser.add_argument("--dry-run", action="store_true", help="Check the URL without editing files")
    args = parser.parse_args()

    url = args.url.strip().rstrip("/")

    if not check_url(url):
        return 1

    if args.dry_run:
        print("Dry run OK. This URL can be used:")
        print(url)
        return 0

    update_readme(url)
    regenerate_report(url)

    print("Updated README.md")
    print("Regenerated docs/project_report.pdf")
    print("GitHub URL:", url)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
