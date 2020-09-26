# Hacktoberfest ([Live Website](https://fineanmol.github.io/Hacktoberfest2k20/Contributors.html))

This is a beginner-friendly project to help you get started with your
[hacktoberfest](https://hacktoberfest.digitalocean.com/). If you don't
know where to start, feel free to watch the videos linked below, and
read the contribution rules. Happy hacking <3 !!

P.S. Star and share this repository, if you had fun!

![Hacktoberfest 2020](https://hacktoberfest.digitalocean.com/assets/HF-full-logo-b05d5eb32b3f3ecc9b2240526104cf4da3187b8b61963dd9042fdc2536e4a76c.svg)


# Videos

- [Hacktoberfest Intro](https://youtu.be/OsAFX_ZbgaE)
- [How to pull request [Overview]](https://youtu.be/DIj2q02gvKs)
- [Merge Conflict / comment](https://youtu.be/zOx5PJTY8CI)


# Contribution rules

- The project must work when opening index.html
- You are allowed to make pull requests that break the rules. We just merge it ;)
- Do NOT add any build steps e.g npm install (we want to keep this a simple static site)
- Do NOT remove other content.
- Styling/code can be pretty, ugly or stupid, big or small as long as it works
- Add your name to the Contributors.html file
- Try to keep pull requests small to minimize merge conflicts


## Getting Started

- Fork this repo (button on top)
- Clone on your local machine

```terminal
git clone https://github.com/fineanmol/Hacktoberfest2k20.git
cd Hacktoberfest2k19
```

- Create a new branch

```markdown
git checkout -b my-new-branch
```
- Add your contribution
- Commit and push

```markdown
git add .
git commit -m "your-commit-msg"
git push origin my-new-branch
```

- Create a new pull request from your forked repository


## Avoid Conflicts (Syncing your fork)

An easy way to avoid conflicts is to add an 'upstream' for your git repo, as other PR's may be merged while you're working on your branch/fork.   

```terminal
git remote add upstream https://github.com/fineanmol/Hacktoberfest2k19
```

You can verify that the new remote has been added by typing
```terminal
git remote -v
```

To pull any new changes from your parent repo simply run
```terminal
git merge upstream/master
```

This will give you any eventual conflicts and allow you to easily solve them in your repo. It's a good idea to use it frequently in between your own commits to make sure that your repo is up to date with its parent.

For more information on syncing forks [read this article from Github](https://help.github.com/articles/syncing-a-fork/).


# FAQs

- Who can contribute?
  - Anyone with a github account and who is signed up for
[hacktoberfest](https://hacktoberfest.digitalocean.com/) :)
- Are you getting paid for this?
  - Sadly no. But we think we should. This is 100% unofficial and we do it for fun, fame and glory.
- Who are you and why are you doing this?
  - We are two programmers from India [Anmol](https://github.com/fineanmol)
  and [Ritesh](https://github.com/ritesh2905). We are doing this because we love Open
  Source and Hacktoberfest. We want to make it easier for people to get started with Hacktoberfest and Open Source.
- Why are you not using digitalocean?
  - Because we only know JavaScript and suck at servers. We use [now](https://zeit.co/now) instead.

- Should I come closer to the text saying 'Don't come closer' on the left side of the home tab ?
  - Nope.
- How many pull request (PR) must be made, if I can get a awesome shirt from Hacktoberfest 2018?
  - 5
- How do I track my progress to get an awesome shirt from Hacktoberfest 2019?
  - go to : https://hacktoberfest.digitalocean.com/stats/ (Scroll down to Check Out Your Own Stats)
- What is the duration of Hacktoberfest 2019?
  - It is from 1st october to 31st october 2019...
- What is the event for?
  - For the open source community engagement



###### *We will do our best to merge as much as possible from everyone. However, time is limited and the merge conflicts are horrible <3*
