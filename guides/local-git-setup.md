# Complete Git Setup


> This page is a work in progress. PRs welcome!<br />
> TODO: I'm going to make instructions clearer, and add screenshots

This document covers:
- [Creating a GitHub Account](#creating-a-github-account)
- [Installing Git](#installing-git)
- [Setting up SSH keys](#setting-up-ssh-keys)
- [Configuring the gitconfig](#configuring-the-gitconfig)


## Creating a GitHub Account

---

## Installing Git

For official installation downloads and docs, see [git-scm.com/downloads](https://git-scm.com/downloads)

### Installing Git on Windows

[Git for Windows](https://gitforwindows.org/) is a complete package of all the basic git tools you'll need, with an easy GUI installer.

1. Download the latest executable from [the Git for Windows Releases](https://github.com/git-for-windows/git/releases)
2. Run the installer (by double clicking on the downloaded .exe file)
3. Follow the on-screen instructions to install git onto your machine
4. Restart explorer.exe (so the new git executable can be found)
5. Run `git --version` to verify that git has been installed correctly

### Installing Git on Mac

The easiest way to install Git on MacOS is via Homebrew.

1. If you don't yet have Brew installed, install it with:
	`/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
2. Then install git with
	`brew install git`
3. Finally, verify git has been installed
	`git --version`

### Installing Git on Linux

On Linux, the best method for installing git is using your system's native package manager. Be sure to update your repositories first. You may need to run install commands as `sudo`

- Debian / Ubuntu: `apt install git`
- Fedora: `dnf install git`
- OpenSUSE: `zypper install git`
- Gentoo: `emerge --ask --verbose dev-vcs/git`
- Arch: `pacman -S git`
- NixOS: `nix-env -i git`
- FreeBSD: `pkg install git`
- OpenBSD: `pkg_add git`
- Alpine: `apk add git`

---

## Setting up SSH keys


### Intro to SSH

When you push to a repo, or make any changes from your local machine, you've got two options for auth, HTTPS or SSH. With HTTPS you'll be prompted to enter a username + password each time you push, whereas with SSH you are authenticated automatically if once your key is setup.

#### What is SSH Auth?
SSH (or Secure SHell) authentication is a method used to establish a secure connection between a client and a server using cryptographic key pairs: a public key (which you share) and a private key (kept secret on your machine).

#### How It Works:
1. You generate an SSH key pair (a public key and a private key).
2. You add the public key to GitHub (or another platform).
3. When connecting to GitHub, it will challenge the client to prove they have the corresponding private key.
4. Your machine uses its private key to respond correctly, verifying your identity without ever revealing the key itself.

#### Benefits Over HTTPS Clone:
- **Security**: Keys are typically more complex than passwords, making them harder to crack.
- **Convenience**: Once set up, no need to enter a username/password with each interaction.
- **Access Control**: Key-based authentication allows finer-grained control, like read-only or full access.

#### Note for New Users:
It's essential to keep your private key secure and never share it. If someone gains access to it, they have access to everything the key provides access to. Also, using a passphrase when generating SSH keys adds an extra layer of security.


### Setting up SSH

#### Generating an SSH key

You may already have a key, in which case you can skip this step. If you do, it'll likely be in a directory named `~/.ssh/`, you can check this by running `ls -al ~/.ssh` - if you see output, and a file ending in `.pub` then you've already got a key!

Otherwise, we'll generate a new key by running:

```bash
ssh-keygen -t ed25519 -C "your_email@example.com"
```

<details><summary>Note for legacy systems</summary>
For legacy systems which does not support Ed25519 algorithm, use:

```bash
ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
```

</details>

When prompted, complete the form (if you choose to set a password, be sure to remember or make note of it!)

Next we should to ensure that the SSH agent is running, and that the key is added to it.

```
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa
```

#### Adding your key to GitHub

Next we need to add the public key to your GitHub profile.

Copy the contents of your newly generated SSH public key (the one ending in `.pub`). You can view the file by running `cat ~/.ssh/id_ed25519.pub` (if you named your key something else, update that accordingly)

Next head over to GitHub, and log into your account
1. Click on your profile photo, then click on Settings.
2. In the left sidebar, click on SSH and GPG keys.
3. Click the New SSH key button.
4. Paste Your Key
5. In the "Title" field, enter a descriptive label (like "My Laptop" or "Work PC").
6. Paste your key into the "Key" field.
7. Click Add SSH key.


---

## Configuring the gitconfig


Like other applications and services, git is configurable through a dotfile. You'll likely find your git config in `~/.gitconfig` - but it can be managed using the `git config` command.

Before we make our first commit, there's a few things we need to setup in the git config. We can do this by running the following commands:

```bash
git config --global user.name "Your Full Name"
git config --global user.email "youremail@example.com"
```

That's all you need for now, but there's many other setting which can be tweaked here, such as setting aliases shorthands, default editor/ conflict / diff programs, enabling features, using plugins, etc. It's also possible (and sometimes preferable) to have different git configurations for different projects.

To learn about those, see the [Git Configuration](https://git-scm.com/book/en/v2/Customizing-Git-Git-Configuration).
