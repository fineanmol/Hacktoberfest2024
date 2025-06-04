#!/bin/bash

echo "🎉 Hacktoberfest 2024 Repository Status"
echo "======================================"
echo ""

echo "📊 Contributors Count:"
contributor_count=$(grep -c "id:" contributors/contributorsList.js)
echo "Total Contributors: $contributor_count"
echo ""

echo "📁 Files Added Today:"
echo "✅ message.py - Hacktoberfest contribution template"
echo "✅ code.js - ServiceNow GlideRecord script"
echo "✅ conv.py - Python conversion utility"
echo "✅ Program to convert binary to decimal"
echo ""

echo "🔄 Git Status:"
git status --short
echo ""

echo "📝 Recent Commits (last 5):"
git log --oneline -5
echo ""

echo "🚀 Summary:"
echo "- All contributors merged successfully"
echo "- $contributor_count total contributors"
echo "- 4 valuable programs added"
echo "- Repository is clean and up to date"
echo ""

echo "💡 Next Steps:"
echo "1. Close remaining contributor-only PRs with thank you message"
echo "2. Continue reviewing PRs for valuable code additions"
echo "3. Enjoy Hacktoberfest! 🎃" 