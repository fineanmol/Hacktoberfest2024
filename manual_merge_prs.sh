#!/bin/bash

# Manual PR merge script - merge PRs one by one
echo "🔧 Manual PR Merge Tool"

# Colors
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m'

# Function to merge a single PR
merge_pr_by_number() {
    local pr_number=$1
    
    echo -e "${BLUE}🔄 Attempting to merge PR #$pr_number${NC}"
    
    # Fetch the PR
    echo "Fetching PR #$pr_number..."
    git fetch origin pull/$pr_number/head:pr-$pr_number
    
    if [ $? -ne 0 ]; then
        echo -e "${RED}❌ Failed to fetch PR #$pr_number${NC}"
        return 1
    fi
    
    # Switch to the PR branch to see what's in it
    git checkout pr-$pr_number
    echo ""
    echo "Files changed in this PR:"
    git diff --name-only master..pr-$pr_number | sed 's/^/  - /'
    echo ""
    
    # Ask user if they want to merge
    read -p "Do you want to merge this PR? (y/n/s for skip): " choice
    
    case $choice in
        y|Y)
            # Attempt merge
            git checkout master
            echo "Merging PR #$pr_number..."
            
            if git merge pr-$pr_number --no-edit; then
                echo -e "${GREEN}✅ Successfully merged PR #$pr_number${NC}"
                echo "Pushing to origin..."
                git push origin master
                git branch -D pr-$pr_number
                return 0
            else
                echo -e "${YELLOW}⚠️  Merge conflicts detected${NC}"
                echo ""
                echo "Conflicted files:"
                git status --porcelain | grep "^UU\|^AA" | sed 's/^.. /  - /'
                echo ""
                echo "You can:"
                echo "1. Resolve conflicts manually and run 'git commit'"
                echo "2. Abort with 'git merge --abort'"
                echo ""
                read -p "Press Enter after resolving conflicts (or 'a' to abort): " resolve_choice
                
                if [ "$resolve_choice" = "a" ]; then
                    git merge --abort
                    git branch -D pr-$pr_number
                    echo "Merge aborted"
                    return 1
                else
                    # Check if conflicts are resolved
                    if git diff --quiet HEAD; then
                        echo -e "${GREEN}✅ Conflicts resolved and committed${NC}"
                        git push origin master
                        git branch -D pr-$pr_number
                        return 0
                    else
                        echo -e "${RED}❌ Conflicts not fully resolved${NC}"
                        return 1
                    fi
                fi
            fi
            ;;
        n|N)
            echo "Skipping merge of PR #$pr_number"
            git checkout master
            git branch -D pr-$pr_number
            return 0
            ;;
        s|S)
            echo "Skipping PR #$pr_number for now"
            git checkout master
            git branch -D pr-$pr_number
            return 0
            ;;
        *)
            echo "Invalid choice"
            git checkout master
            git branch -D pr-$pr_number
            return 1
            ;;
    esac
}

# Function to show contributor info from a PR
show_pr_contributor_info() {
    local pr_number=$1
    
    echo "Checking if PR #$pr_number adds a contributor..."
    git fetch origin pull/$pr_number/head:pr-$pr_number
    git checkout pr-$pr_number
    
    # Check if contributorsList.js is modified
    if git diff --name-only master..pr-$pr_number | grep -q "contributors/contributorsList.js"; then
        echo "This PR modifies contributors list:"
        git diff master..pr-$pr_number contributors/contributorsList.js | grep "^+" | grep -E "(fullname|username)" | head -4
    else
        echo "This PR does not modify the contributors list"
    fi
    
    git checkout master
    git branch -D pr-$pr_number 2>/dev/null
}

# Main menu
echo "Manual PR Merge Options:"
echo "1. Merge specific PR number"
echo "2. Merge a list of PR numbers"
echo "3. Show contributor info for a PR"
echo "4. Show current git status"
echo "5. List recent commits"
read -p "Enter choice (1-5): " main_choice

case $main_choice in
    1)
        read -p "Enter PR number to merge: " pr_num
        if [ ! -z "$pr_num" ]; then
            merge_pr_by_number $pr_num
        fi
        ;;
    2)
        echo "Enter PR numbers to merge (space-separated):"
        read -p "PR numbers: " pr_list
        for pr_num in $pr_list; do
            echo ""
            echo "=" × 50
            merge_pr_by_number $pr_num
            echo ""
            read -p "Continue to next PR? (y/n): " continue_choice
            if [ "$continue_choice" != "y" ]; then
                break
            fi
        done
        ;;
    3)
        read -p "Enter PR number to check: " pr_num
        if [ ! -z "$pr_num" ]; then
            show_pr_contributor_info $pr_num
        fi
        ;;
    4)
        echo "Current git status:"
        git status
        ;;
    5)
        echo "Recent commits:"
        git log --oneline -10
        ;;
    *)
        echo "Invalid choice"
        ;;
esac

echo ""
echo "✅ Manual merge session complete!" 