#!/bin/bash

# Script to fix PR conflicts one by one
echo "🔧 Manual PR Conflict Resolution Helper"

REPO="fineanmol/Hacktoberfest2024"

# Colors
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m'

# Function to merge a single PR with conflict resolution
merge_single_pr() {
    local pr_number=$1
    
    echo -e "${BLUE}🔄 Processing PR #$pr_number${NC}"
    
    # Get PR info
    pr_info=$(curl -s "https://api.github.com/repos/$REPO/pulls/$pr_number")
    pr_title=$(echo "$pr_info" | jq -r '.title')
    pr_author=$(echo "$pr_info" | jq -r '.user.login')
    pr_mergeable=$(echo "$pr_info" | jq -r '.mergeable')
    
    echo "Title: $pr_title"
    echo "Author: @$pr_author"
    echo "Mergeable: $pr_mergeable"
    echo ""
    
    # Show files changed
    echo "Files changed:"
    curl -s "https://api.github.com/repos/$REPO/pulls/$pr_number/files" | \
        jq -r '.[].filename' | sed 's/^/  - /'
    echo ""
    
    # Ask user what to do
    echo "What would you like to do?"
    echo "1. Try to merge automatically"
    echo "2. Merge manually with conflict resolution"
    echo "3. Close this PR (contributor already merged)"
    echo "4. Skip for now"
    read -p "Enter choice (1-4): " choice
    
    case $choice in
        1)
            # Try automatic merge
            echo "Attempting automatic merge..."
            git fetch origin pull/$pr_number/head:pr-$pr_number
            git checkout master
            
            if git merge pr-$pr_number --no-edit; then
                echo -e "${GREEN}✅ Successfully merged PR #$pr_number automatically${NC}"
                git push origin master
                git branch -D pr-$pr_number
                return 0
            else
                echo -e "${RED}❌ Automatic merge failed - conflicts detected${NC}"
                git merge --abort
                git branch -D pr-$pr_number
                return 1
            fi
            ;;
        2)
            # Manual merge with conflict resolution
            echo "Starting manual merge process..."
            git fetch origin pull/$pr_number/head:pr-$pr_number
            git checkout master
            
            echo "Attempting merge..."
            if ! git merge pr-$pr_number --no-edit; then
                echo -e "${YELLOW}⚠️  Conflicts detected. Opening conflict resolution...${NC}"
                echo ""
                echo "Conflicted files:"
                git status --porcelain | grep "^UU" | sed 's/^UU /  - /'
                echo ""
                echo "🔧 Please resolve conflicts manually:"
                echo "1. Edit the conflicted files"
                echo "2. Remove conflict markers (<<<<<<< ======= >>>>>>>)"
                echo "3. Stage files: git add <filename>"
                echo "4. Commit: git commit"
                echo ""
                echo "Common conflict resolution for contributorsList.js:"
                echo "- Keep the existing contributors"
                echo "- Add the new contributor at the end with next ID"
                echo "- Remove duplicate entries"
                echo ""
                read -p "Press Enter when conflicts are resolved and committed..."
                
                # Check if merge was completed
                if ! git diff --quiet HEAD; then
                    echo -e "${RED}❌ Merge not completed. Please finish the merge.${NC}"
                    return 1
                else
                    echo -e "${GREEN}✅ Conflicts resolved and committed${NC}"
                    git push origin master
                    git branch -D pr-$pr_number
                    return 0
                fi
            else
                echo -e "${GREEN}✅ No conflicts - merged successfully${NC}"
                git push origin master
                git branch -D pr-$pr_number
                return 0
            fi
            ;;
        3)
            # Close PR (contributor already merged)
            echo -e "${YELLOW}Marking PR #$pr_number for closure${NC}"
            echo "$pr_number|$pr_author|$pr_title" >> prs_to_close_manually.txt
            echo "Added to prs_to_close_manually.txt"
            return 0
            ;;
        4)
            # Skip
            echo "Skipping PR #$pr_number"
            return 0
            ;;
        *)
            echo "Invalid choice"
            return 1
            ;;
    esac
}

# Function to show conflict resolution tips
show_conflict_tips() {
    echo -e "${BLUE}🛠  Conflict Resolution Tips:${NC}"
    echo ""
    echo "For contributorsList.js conflicts:"
    echo "1. Open the file in your editor"
    echo "2. Look for conflict markers:"
    echo "   <<<<<<< HEAD"
    echo "   (current master content)"
    echo "   ======="
    echo "   (PR content)"
    echo "   >>>>>>> pr-branch"
    echo ""
    echo "3. Resolution strategy:"
    echo "   - Keep all existing contributors from master"
    echo "   - Add the new contributor from PR at the end"
    echo "   - Assign next available ID number"
    echo "   - Remove duplicate entries"
    echo ""
    echo "4. After editing:"
    echo "   git add contributors/contributorsList.js"
    echo "   git commit"
    echo ""
}

# Main execution
echo "PR Conflict Resolution Options:"
echo "1. Process PRs one by one interactively"
echo "2. Show conflict resolution tips"
echo "3. Process specific PR number"
echo "4. Show current git status"
read -p "Enter choice (1-4): " main_choice

case $main_choice in
    1)
        # Interactive processing
        if [ ! -f "prs_with_conflicts.txt" ]; then
            echo "❌ prs_with_conflicts.txt not found. Run merge_remaining_prs.sh first."
            exit 1
        fi
        
        echo "Processing PRs with conflicts..."
        while IFS='|' read -r pr_number author title; do
            echo ""
            echo "=" × 50
            merge_single_pr $pr_number
            echo ""
            read -p "Continue to next PR? (y/n): " continue_choice
            if [ "$continue_choice" != "y" ]; then
                break
            fi
        done < prs_with_conflicts.txt
        ;;
    2)
        show_conflict_tips
        ;;
    3)
        read -p "Enter PR number: " pr_num
        if [ ! -z "$pr_num" ]; then
            merge_single_pr $pr_num
        fi
        ;;
    4)
        echo "Current git status:"
        git status
        ;;
    *)
        echo "Invalid choice"
        ;;
esac

echo ""
echo "✅ Conflict resolution session complete!" 