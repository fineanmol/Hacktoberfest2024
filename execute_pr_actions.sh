#!/bin/bash

# Execute PR merge and close actions
echo "🚀 Executing PR actions..."

REPO="fineanmol/Hacktoberfest2024"

# Colors
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m'

# Thank you message template for contributor PRs
CONTRIBUTOR_MESSAGE="🎉 Thank you for your contribution to Hacktoberfest 2024!

Your changes have been merged automatically into the main branch to resolve the merge conflicts that occur when multiple contributors edit the same file simultaneously.

✅ Your contribution is now live in the contributors list!
🌟 You're officially part of the Hacktoberfest 2024 contributors!

Thank you for participating in open source! 🚀

#Hacktoberfest #OpenSource"

# Function to close a PR with a comment
close_pr_with_comment() {
    local pr_number=$1
    local author=$2
    local title=$3
    
    echo -e "${YELLOW}Closing PR #$pr_number by @$author${NC}"
    
    # Add comment
    curl -s -X POST \
        -H "Accept: application/vnd.github.v3+json" \
        -H "Authorization: token YOUR_GITHUB_TOKEN" \
        "https://api.github.com/repos/$REPO/issues/$pr_number/comments" \
        -d "{\"body\":\"$CONTRIBUTOR_MESSAGE\"}" > /dev/null
    
    # Close PR
    curl -s -X PATCH \
        -H "Accept: application/vnd.github.v3+json" \
        -H "Authorization: token YOUR_GITHUB_TOKEN" \
        "https://api.github.com/repos/$REPO/pulls/$pr_number" \
        -d '{"state":"closed"}' > /dev/null
    
    echo "  ✅ Closed PR #$pr_number"
}

# Function to merge a PR
merge_pr() {
    local pr_number=$1
    local author=$2
    local title=$3
    
    echo -e "${GREEN}Merging PR #$pr_number by @$author${NC}"
    
    # Try to merge
    result=$(curl -s -X PUT \
        -H "Accept: application/vnd.github.v3+json" \
        -H "Authorization: token YOUR_GITHUB_TOKEN" \
        "https://api.github.com/repos/$REPO/pulls/$pr_number/merge" \
        -d '{"commit_title":"Merge PR #'$pr_number': '$title'","merge_method":"merge"}')
    
    # Check if merge was successful
    if echo "$result" | grep -q "merged"; then
        echo "  ✅ Successfully merged PR #$pr_number"
    else
        echo "  ❌ Failed to merge PR #$pr_number"
        echo "  Error: $(echo "$result" | jq -r '.message // "Unknown error"')"
        echo "$pr_number|$author|$title|MERGE_FAILED" >> failed_actions.txt
    fi
}

# Function to use GitHub CLI (if available)
use_github_cli() {
    echo "🔧 Using GitHub CLI for PR management..."
    
    # Close contributor-only PRs
    if [ -f "prs_to_close_contributors.txt" ] && [ -s "prs_to_close_contributors.txt" ]; then
        echo -e "${YELLOW}Closing contributor-only PRs...${NC}"
        while IFS='|' read -r pr_number author title; do
            echo "Closing PR #$pr_number..."
            gh pr close $pr_number --comment "$CONTRIBUTOR_MESSAGE" || echo "Failed to close PR #$pr_number"
        done < prs_to_close_contributors.txt
    fi
    
    # Merge valuable PRs
    if [ -f "prs_to_merge.txt" ] && [ -s "prs_to_merge.txt" ]; then
        echo -e "${GREEN}Merging valuable PRs...${NC}"
        while IFS='|' read -r pr_number author title; do
            echo "Merging PR #$pr_number..."
            gh pr merge $pr_number --merge --delete-branch || echo "Failed to merge PR #$pr_number"
        done < prs_to_merge.txt
    fi
}

# Function to manually merge using git
manual_git_merge() {
    local pr_number=$1
    local author=$2
    
    echo -e "${BLUE}Manually merging PR #$pr_number...${NC}"
    
    # Get PR branch info
    pr_info=$(curl -s "https://api.github.com/repos/$REPO/pulls/$pr_number")
    head_ref=$(echo "$pr_info" | jq -r '.head.ref')
    head_repo=$(echo "$pr_info" | jq -r '.head.repo.clone_url')
    
    # Fetch and merge
    git fetch origin pull/$pr_number/head:pr-$pr_number
    git checkout pr-$pr_number
    
    # Check for conflicts
    git checkout master
    if git merge pr-$pr_number --no-commit --no-ff; then
        # No conflicts, commit the merge
        git commit -m "Merge PR #$pr_number from @$author"
        git branch -D pr-$pr_number
        echo "  ✅ Successfully merged PR #$pr_number"
        return 0
    else
        # Conflicts detected
        git merge --abort
        git branch -D pr-$pr_number
        echo "  ⚠️  Conflicts in PR #$pr_number - needs manual resolution"
        return 1
    fi
}

# Main execution
echo "Select merge strategy:"
echo "1. Use GitHub CLI (recommended if available)"
echo "2. Use GitHub API (requires token)"
echo "3. Manual git merge (for conflicts)"
echo "4. Show analysis only"
read -p "Enter choice (1-4): " choice

case $choice in
    1)
        # Check if GitHub CLI is available
        if command -v gh &> /dev/null; then
            use_github_cli
        else
            echo "❌ GitHub CLI not found. Install with: brew install gh"
            echo "Then authenticate with: gh auth login"
        fi
        ;;
    2)
        echo "⚠️  GitHub API method requires a personal access token"
        echo "Set YOUR_GITHUB_TOKEN in the script or use environment variable"
        ;;
    3)
        echo "🔧 Manual git merge mode"
        if [ -f "prs_to_merge.txt" ]; then
            while IFS='|' read -r pr_number author title; do
                manual_git_merge $pr_number $author
            done < prs_to_merge.txt
        fi
        ;;
    4)
        echo "📊 Analysis files created. Review them manually:"
        echo "- prs_to_merge.txt"
        echo "- prs_to_close_contributors.txt"
        echo "- prs_with_conflicts.txt"
        echo "- prs_other_changes.txt"
        ;;
    *)
        echo "Invalid choice"
        ;;
esac

echo ""
echo "✅ PR action execution complete!" 