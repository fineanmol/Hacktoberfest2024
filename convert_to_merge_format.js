#!/usr/bin/env node

/**
 * Convert extracted contributors JSON to merge script format
 */

const fs = require('fs');

console.log('🔄 Converting extracted contributors to merge format...\n');

// Read extracted contributors
let extractedContributors = [];
try {
    const jsonData = fs.readFileSync('extracted_contributors.json', 'utf8');
    extractedContributors = JSON.parse(jsonData);
} catch (error) {
    console.error('❌ Error reading extracted_contributors.json:', error.message);
    console.log('\n💡 Make sure to run ./auto_extract_contributors.sh first');
    process.exit(1);
}

if (extractedContributors.length === 0) {
    console.log('❌ No contributors found in extracted_contributors.json');
    process.exit(1);
}

console.log(`📊 Found ${extractedContributors.length} contributors\n`);

// Convert to merge script format
const mergeFormat = extractedContributors.map(contributor => {
    return `  { fullname: "${contributor.fullname}", username: "${contributor.username}" }, // PR #${contributor.pr_number} by @${contributor.pr_author}`;
}).join('\n');

// Read the current merge script
let mergeScriptContent = '';
try {
    mergeScriptContent = fs.readFileSync('merge_prs_script.js', 'utf8');
} catch (error) {
    console.error('❌ Error reading merge_prs_script.js:', error.message);
    process.exit(1);
}

// Replace the newContributors array
const newContributorsSection = `const newContributors = [
${mergeFormat}
];`;

// Update the merge script
const updatedContent = mergeScriptContent.replace(
    /const newContributors = \[[\s\S]*?\];/,
    newContributorsSection
);

// Write updated merge script
fs.writeFileSync('merge_prs_script.js', updatedContent);

console.log('✅ Updated merge_prs_script.js with extracted contributors!');
console.log('\n📋 Contributors added:');
extractedContributors.forEach((contrib, index) => {
    console.log(`${index + 1}. ${contrib.fullname} (PR #${contrib.pr_number})`);
});

console.log('\n🚀 Next steps:');
console.log('1. Review the updated merge_prs_script.js');
console.log('2. Run: node merge_prs_script.js');
console.log('3. Commit and push the changes');
console.log('4. Close all PRs with a thank you message');

// Also create a summary file
const summary = {
    total_contributors: extractedContributors.length,
    extraction_date: new Date().toISOString(),
    contributors: extractedContributors,
    next_steps: [
        'Review merge_prs_script.js',
        'Run node merge_prs_script.js',
        'Commit and push changes',
        'Close PRs with thank you messages'
    ]
};

fs.writeFileSync('merge_summary.json', JSON.stringify(summary, null, 2));
console.log('\n📄 Detailed summary saved to merge_summary.json'); 