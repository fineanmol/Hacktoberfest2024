# Submit your first PR (Terminal)

> This page is a work in progress. PRs welcome!<br />
> TODO: I'm going to make instructions clearer, and add screenshots


### 1. Fork the Repository

- Start by visiting the GitHub page of the repository you wish to contribute to.
- In the top-right corner of the page, click the "Fork" button. This will create a copy of the repository under your GitHub account.

### 2. Clone Your Forked Repository

- On your forked repository's main page, click the green "Code" button. Copy the URL provided.
- Open your terminal or command prompt and navigate to the directory where you want to clone the repository.
   Enter:

```bash
git clone [URL you copied]
```

This will create a local copy of your forked repository on your machine.


### 3. Navigate to the Repository's Directory

Enter:

```bash
cd [repository-name]
```

### 4. Set Upstream Remote

To keep track of the original repository (often called the "upstream"), enter:

```bash
git remote add upstream [original repository's URL]
```

### 5. Create a New Branch

Always make changes in a new branch instead of directly on main or master. To create and switch to a new branch, enter:

```bash
git checkout -b [branch-name]
```

Choose a descriptive branch name related to the changes you're planning to make.

### 6. Make Your Changes

Edit, add, or remove files as needed using your preferred text editor or IDE.

### 7. Stage and Commit Changes

Stage your changes with:

```bash
git add .
```

Commit your changes with a descriptive message:

```bash
git commit -m "Brief description of changes made"
```

### 8. Push Changes to Your Fork

Push your changes to your forked repository on GitHub:

```bash
git push origin [branch-name]
```

### 9. Open a Pull Request (PR)

- Go back to your forked repository on GitHub.
- Click the "New pull request" button (often GitHub will also present a quick link to create a PR from your recently pushed branch).
- Ensure the base repository is the original repository you want to contribute to, and the head repository is your fork. Also, make sure the branch shown for your fork is the one you just pushed.
- Fill in the PR title and description, detailing your changes and the reason for them.
- Click "Create pull request".

### 10. Await Feedback

- The maintainers of the original repository will review your PR.
- They might request some changes. If they do, repeat steps 6-8, and the PR will automatically update with your new changes.
- Engage in any discussions, answer questions, and make necessary changes as needed.

### 11. Keep Your Fork Synced

Before starting new work, it's a good practice to fetch and merge changes from the upstream (original) repository:

```bash
git checkout main
git fetch upstream
git merge upstream/main
git push origin main
```

### 12. Celebrate!

Once your PR is merged, you've made a successful contribution!
