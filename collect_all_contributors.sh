#!/bin/bash

# Collect contributors from open PRs
echo "🔍 Collecting contributors from open PRs..."

REPO="fineanmol/Hacktoberfest2024"
OUTPUT="new_contributors_list.txt"

# Clear output file
> $OUTPUT

# Array of PR numbers that likely have contributor changes
PR_NUMBERS="8147 8146 8140 8138 8136 8133 8132 8127 8125 8124 8120 8119 8117 8116 8115 8113 8110 8106 8105 8102 8101 8100 8098 8097 8096 8095 8093 8087 8086 8084 8081 8080 8079 8078 8076 8075 8072 8071 8069 8068 8067 8065 8063 8057 8055 8053 8051 8050 8048 8047 8046 8045 8044 8043 8042 8041 8040 8039 8037 8035 8034 8033 8030 8027 8026 8025 8021 8017 8016 8015 8014 8012 8008 8007 8004 8002 7998 7996 7995 7993 7992 7989 7987 7982 7977 7976 7975 7971 7970 7968 7967 7966 7964 7963 7962 7961 7960 7959 7958 7955"

echo "Checking $(echo $PR_NUMBERS | wc -w) PRs..."

for pr in $PR_NUMBERS; do
    echo -n "PR #$pr: "
    
    # Get patch for contributors file
    patch=$(curl -s "https://api.github.com/repos/$REPO/pulls/$pr/files" 2>/dev/null | \
            jq -r '.[] | select(.filename == "contributors/contributorsList.js") | .patch' 2>/dev/null)
    
    if [ -n "$patch" ] && [ "$patch" != "null" ]; then
        # Extract fullname and username
        fullname=$(echo "$patch" | grep "^+" | grep "fullname" | sed 's/.*fullname.*['"'"'"]\([^'"'"'"]*\)['"'"'"].*/\1/' | head -1)
        username=$(echo "$patch" | grep "^+" | grep "username" | sed 's/.*username.*['"'"'"]\([^'"'"'"]*\)['"'"'"].*/\1/' | head -1)
        
        if [ -n "$fullname" ] && [ -n "$username" ]; then
            echo "{ fullname: \"$fullname\", username: \"$username\" }," >> $OUTPUT
            echo "✓ $fullname"
        else
            echo "no contributor data"
        fi
    else
        echo "no changes to contributors file"
    fi
    
    # Rate limiting
    sleep 0.2
done

echo ""
echo "✅ Collection complete! Found $(wc -l < $OUTPUT) contributors"
echo "�� Saved to: $OUTPUT" 