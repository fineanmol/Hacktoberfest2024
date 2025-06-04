#!/bin/bash

# Script to systematically merge or close remaining open PRs
echo "🔄 Processing remaining open PRs..."

REPO="fineanmol/Hacktoberfest2024"

# Colors for output
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m'

# Get all open PR numbers
echo "📋 Fetching open PRs..."
PR_NUMBERS=$(curl -s "https://api.github.com/repos/$REPO/pulls?state=open&per_page=100" | \
  jq -r '.[].number' 2>/dev/null | sort -n)

if [ -z "$PR_NUMBERS" ]; then
    echo "❌ Failed to fetch PRs"
    exit 1
fi

PR_COUNT=$(echo "$PR_NUMBERS" | wc -l | tr -d ' ')
echo "Found $PR_COUNT open PRs"
echo ""

# Create output files for different actions
> prs_to_merge.txt
> prs_to_close_contributors.txt  
> prs_with_conflicts.txt
> prs_other_changes.txt

# Analyze each PR
for pr_number in $PR_NUMBERS; do
    echo -e "${BLUE}Analyzing PR #$pr_number...${NC}"
    
    # Get PR details
    pr_info=$(curl -s "https://api.github.com/repos/$REPO/pulls/$pr_number" 2>/dev/null)
    pr_title=$(echo "$pr_info" | jq -r '.title' 2>/dev/null)
    pr_author=$(echo "$pr_info" | jq -r '.user.login' 2>/dev/null)
    pr_mergeable=$(echo "$pr_info" | jq -r '.mergeable' 2>/dev/null)
    
    echo "  Title: $pr_title"
    echo "  Author: @$pr_author"
    echo "  Mergeable: $pr_mergeable"
    
    # Get files changed
    files_changed=$(curl -s "https://api.github.com/repos/$REPO/pulls/$pr_number/files" 2>/dev/null | \
      jq -r '.[].filename' 2>/dev/null)
    
    # Count total files changed
    file_count=$(echo "$files_changed" | wc -l | tr -d ' ')
    echo "  Files changed: $file_count"
    
    # Check if only contributors file is modified
    contributors_only=false
    if echo "$files_changed" | grep -q "contributors/contributorsList.js"; then
        other_files=$(echo "$files_changed" | grep -v "contributors/contributorsList.js" | wc -l | tr -d ' ')
        if [ "$other_files" = "0" ]; then
            contributors_only=true
        fi
    fi
    
    # Categorize the PR
    if [ "$contributors_only" = "true" ]; then
        echo -e "  ${YELLOW}→ Contributors only - will close${NC}"
        echo "$pr_number|$pr_author|$pr_title" >> prs_to_close_contributors.txt
    elif [ "$pr_mergeable" = "true" ]; then
        echo -e "  ${GREEN}→ Can merge - has other valuable changes${NC}"
        echo "$pr_number|$pr_author|$pr_title" >> prs_to_merge.txt
    elif [ "$pr_mergeable" = "false" ]; then
        echo -e "  ${RED}→ Has conflicts - needs manual review${NC}"
        echo "$pr_number|$pr_author|$pr_title" >> prs_with_conflicts.txt
    else
        echo -e "  ${BLUE}→ Other changes - needs review${NC}"
        echo "$pr_number|$pr_author|$pr_title" >> prs_other_changes.txt
    fi
    
    echo ""
    sleep 0.1  # Rate limiting
done

# Summary
echo "📊 Analysis Summary:"
echo "==================="
echo "PRs to merge (valuable changes): $(wc -l < prs_to_merge.txt)"
echo "PRs to close (contributors only): $(wc -l < prs_to_close_contributors.txt)"
echo "PRs with conflicts: $(wc -l < prs_with_conflicts.txt)"
echo "PRs needing review: $(wc -l < prs_other_changes.txt)"
echo ""

echo "📝 Created analysis files:"
echo "- prs_to_merge.txt"
echo "- prs_to_close_contributors.txt"  
echo "- prs_with_conflicts.txt"
echo "- prs_other_changes.txt"
echo ""

echo "🚀 Next: Run the merge/close commands based on these files" 