#!/bin/bash

# Script to help collect contributors from open PRs
# GitHub API script for fineanmol/Hacktoberfest2024

echo "🔍 Fetching open pull requests from GitHub..."

# Colors for output
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

REPO="fineanmol/Hacktoberfest2024"

echo -e "${BLUE}Repository: ${REPO}${NC}"
echo ""

# Fetch open PRs using GitHub API
echo "📋 Open Pull Requests:"
echo "========================"

# Basic API call to get open PRs (first 100)
curl -s "https://api.github.com/repos/${REPO}/pulls?state=open&per_page=100" | \
  jq -r '.[] | "PR #\(.number): \(.title) by @\(.user.login)"' 2>/dev/null || {
    echo "❌ jq not found. Using basic curl output:"
    curl -s "https://api.github.com/repos/${REPO}/pulls?state=open&per_page=30" | \
      grep -E '"number"|"title"|"login"' | \
      sed 'N;N;s/\n/ /g' | \
      sed 's/.*"number": \([0-9]*\).*"title": "\([^"]*\)".*"login": "\([^"]*\)".*/PR #\1: \2 by @\3/'
  }

echo ""
echo -e "${YELLOW}📝 Next Steps:${NC}"
echo "1. For each PR above, visit: https://github.com/${REPO}/pull/[PR_NUMBER]"
echo "2. Look for changes to contributors/contributorsList.js"
echo "3. Copy the new contributor object (name and GitHub username)"
echo "4. Add them to the merge_prs_script.js file"
echo ""
echo -e "${GREEN}💡 Tip: Look for additions that look like:${NC}"
echo "  {"
echo "    id: XXX,"
echo "    fullname: \"Name\","
echo "    username: \"https://github.com/username\","
echo "  }"
echo ""
echo -e "${BLUE}🚀 Once you've collected all contributors, run:${NC}"
echo "  node merge_prs_script.js" 