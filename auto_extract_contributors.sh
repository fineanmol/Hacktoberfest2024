#!/bin/bash

# Advanced script to automatically extract contributors from open PRs
# This will fetch the actual changes and extract new contributors

echo "🚀 Auto-extracting contributors from open PRs..."

REPO="fineanmol/Hacktoberfest2024"
OUTPUT_FILE="extracted_contributors.json"

# Colors
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m'

echo -e "${BLUE}Repository: ${REPO}${NC}"
echo "Output: ${OUTPUT_FILE}"
echo ""

# Create output file
echo "[" > ${OUTPUT_FILE}

# Counter for valid contributors
count=0

# Get PR numbers that modify contributorsList.js
echo "🔍 Finding PRs that modify contributorsList.js..."

# Get all open PRs and check which ones modify the contributors file
PR_NUMBERS=$(curl -s "https://api.github.com/repos/${REPO}/pulls?state=open&per_page=100" | \
  jq -r '.[].number' 2>/dev/null)

if [ -z "$PR_NUMBERS" ]; then
    echo "❌ Failed to fetch PRs. Trying alternative method..."
    exit 1
fi

echo "Found PRs: $(echo $PR_NUMBERS | wc -w)"
echo ""

for pr_number in $PR_NUMBERS; do
    echo -n "Checking PR #${pr_number}... "
    
    # Get the files changed in this PR
    files_changed=$(curl -s "https://api.github.com/repos/${REPO}/pulls/${pr_number}/files" | \
      jq -r '.[].filename' 2>/dev/null)
    
    # Check if contributorsList.js is modified
    if echo "$files_changed" | grep -q "contributors/contributorsList.js"; then
        echo -e "${GREEN}✓ Contributors file modified${NC}"
        
        # Get the patch/diff
        patch=$(curl -s "https://api.github.com/repos/${REPO}/pulls/${pr_number}/files" | \
          jq -r '.[] | select(.filename == "contributors/contributorsList.js") | .patch' 2>/dev/null)
        
        if [ ! -z "$patch" ]; then
            # Extract new contributors from the patch (lines starting with +)
            new_lines=$(echo "$patch" | grep "^+" | grep -E "(fullname|username)" | head -10)
            
            if [ ! -z "$new_lines" ]; then
                # Try to extract fullname and username
                fullname=$(echo "$new_lines" | grep "fullname" | sed 's/.*fullname.*['"'"'"]\([^'"'"'"]*\)['"'"'"].*/\1/' | head -1)
                username=$(echo "$new_lines" | grep "username" | sed 's/.*username.*['"'"'"]\([^'"'"'"]*\)['"'"'"].*/\1/' | head -1)
                
                if [ ! -z "$fullname" ] && [ ! -z "$username" ]; then
                    # Get PR author info
                    pr_author=$(curl -s "https://api.github.com/repos/${REPO}/pulls/${pr_number}" | \
                      jq -r '.user.login' 2>/dev/null)
                    
                    # Add comma if not first entry
                    if [ $count -gt 0 ]; then
                        echo "," >> ${OUTPUT_FILE}
                    fi
                    
                    # Add to JSON file
                    cat >> ${OUTPUT_FILE} << EOF
  {
    "pr_number": ${pr_number},
    "fullname": "${fullname}",
    "username": "${username}",
    "pr_author": "${pr_author}"
  }EOF
                    
                    echo "    → Added: ${fullname} (${username})"
                    count=$((count + 1))
                else
                    echo "    → Could not extract contributor info"
                fi
            else
                echo "    → No new contributor lines found"
            fi
        else
            echo "    → Could not get patch"
        fi
    else
        echo "skip"
    fi
    
    # Rate limiting
    sleep 0.1
done

echo "]" >> ${OUTPUT_FILE}

echo ""
echo -e "${GREEN}✅ Extraction complete!${NC}"
echo "Found ${count} contributors in ${OUTPUT_FILE}"
echo ""

if [ $count -gt 0 ]; then
    echo -e "${YELLOW}📋 Summary of extracted contributors:${NC}"
    jq -r '.[] | "• \(.fullname) - \(.username) (PR #\(.pr_number))"' ${OUTPUT_FILE} 2>/dev/null || {
        echo "Raw JSON saved to ${OUTPUT_FILE}"
    }
    
    echo ""
    echo -e "${BLUE}🔄 Next: Convert to merge script format${NC}"
    echo "Run: node convert_to_merge_format.js"
else
    echo -e "${RED}❌ No contributors found. You may need to manually check the PRs.${NC}"
fi 