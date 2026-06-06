# GitHub Submission Steps

Use these steps after creating a GitHub account or logging in to your existing account.

## 1. Create Repository on GitHub

Create a new public repository with this exact name:

```text
HITEC-OOP-SCMS-25-CS-067
```

Do not add README, `.gitignore`, or license on GitHub because this local folder already has those files.

## 2. Push This Local Project

Open PowerShell and run:

```powershell
cd D:\HITEC-OOP-SCMS-25-CS-067
git remote add origin https://github.com/YOUR_USERNAME/HITEC-OOP-SCMS-25-CS-067.git
git branch -M main
git push -u origin main
```

Replace `YOUR_USERNAME` with your real GitHub username.

If Git says `remote origin already exists`, run this instead:

```powershell
git remote set-url origin https://github.com/YOUR_USERNAME/HITEC-OOP-SCMS-25-CS-067.git
git push -u origin main
```

## 3. Update Final URL

After the push, copy your public repository URL and paste it in:

- `README.md`
- `docs/project_report.pdf`

You can update both with one command:

```powershell
cd D:\HITEC-OOP-SCMS-25-CS-067
python tools\finalize_github_url.py https://github.com/YOUR_USERNAME/HITEC-OOP-SCMS-25-CS-067
```

To check the URL format without changing files:

```powershell
python tools\finalize_github_url.py --dry-run https://github.com/YOUR_USERNAME/HITEC-OOP-SCMS-25-CS-067
```

The URL should look like:

```text
https://github.com/YOUR_USERNAME/HITEC-OOP-SCMS-25-CS-067
```

## 4. Check GitHub Actions

Open the repository on GitHub and click the `Actions` tab. The included workflow should compile the project, run a menu smoke test, and check that both report files are generated.

## 5. Submit

Submit the public GitHub URL on the course portal before the deadline.
