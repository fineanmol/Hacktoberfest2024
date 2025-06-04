#!/usr/bin/env node

/**
 * Quick PR Merge Script for Hacktoberfest2024
 * Add all new contributors here and run to merge them all at once
 */

const fs = require('fs');
const path = require('path');

// =============================================================================
// ADD ALL NEW CONTRIBUTORS HERE
// =============================================================================
// Copy the contributor info from each PR and add them in this format:
// { fullname: "Full Name", username: "https://github.com/username" }

const newContributors = [
    // All contributors collected from open PRs that modify contributorsList.js
    { fullname: "Khushi Pandey", username: "https://github.com/KhushiPandey8" },
    { fullname: "Uday Merugu", username: "https://github.com/udayuvraj" },
    { fullname: "Raaz Ghosh", username: "https://github.com/raazghosh" },
    { fullname: "Derek Williams", username: "https://github.com/derk78" },
    { fullname: "Surya Prakash Subudhiray", username: "https://github.com/SuryaAbyss" },
    { fullname: "Arshad Ariff", username: "https://github.com/ArshadAriff" },
    { fullname: "Gokul M", username: "https://github.com/Gokul-MK" },
    { fullname: "Vinay Kondabathula", username: "https://github.com/VinayK8866" },
    { fullname: "Yigit Yildirim", username: "https://github.com/yigityildirim45" },
    { fullname: "Daniella E.", username: "https://github.com/git-ellea" },
    { fullname: "Jude Shaveen", username: "https://github.com/Shaveenblu" },
    { fullname: "Abhinav Bansal", username: "https://github.com/BansalAbhinav" },
    { fullname: "Satyam Singh", username: "https://github.com/satmm" },
    { fullname: "Suvam Das", username: "https://github.com/vamus092" },
    { fullname: "Sachin kumar", username: "https://github.com/Sharmaji513" },
    { fullname: "Nishant Gaurav", username: "https://github.com/Imbiber" },
    { fullname: "Shivangi Bhargava", username: "https://github.com/ShivangiBhargava" },
    { fullname: "Sayantan Nandi", username: "https://github.com/sayantann7" },
    { fullname: "Aman Raj", username: "https://github.com/amanraj77" },
    { fullname: "Bailey Henderson", username: "https://github.com/BaileyKH" },
    { fullname: "Jinwoo Jung", username: "https://github.com/wlsdn2749" },
    { fullname: "Akshat Tripathi", username: "https://github.com/TripathiAkshat" },
    { fullname: "Inchara J", username: "https://github.com/Incharajayaram" },
];

// =============================================================================
// MERGE LOGIC - DON'T EDIT BELOW THIS LINE
// =============================================================================

function readContributorsList() {
    const filePath = path.join(__dirname, 'contributors', 'contributorsList.js');
    const content = fs.readFileSync(filePath, 'utf8');
    
    // Extract the contributors array
    const arrayMatch = content.match(/contributors = \[([\s\S]*)\];/);
    if (!arrayMatch) {
        throw new Error('Could not parse contributors array');
    }
    
    return {
        content: content,
        arrayContent: arrayMatch[1]
    };
}

function parseContributors(arrayContent) {
    const contributors = [];
    const regex = /{\s*id:\s*(\d+),\s*fullname:\s*['"](.*?)['"],\s*username:\s*['"](.*?)['"],?\s*}/g;
    
    let match;
    while ((match = regex.exec(arrayContent)) !== null) {
        contributors.push({
            id: parseInt(match[1]),
            fullname: match[2],
            username: match[3]
        });
    }
    
    return contributors;
}

function getNextId(contributors) {
    const ids = contributors.map(c => c.id);
    return Math.max(...ids) + 1;
}

function contributorExists(contributors, fullname, username) {
    return contributors.some(c => 
        c.fullname.toLowerCase().trim() === fullname.toLowerCase().trim() || 
        c.username.toLowerCase() === username.toLowerCase()
    );
}

function formatContributor(contributor) {
    return `  {
    id: ${contributor.id},
    fullname: "${contributor.fullname}",
    username: "${contributor.username}",
  }`;
}

function mergeAllContributors() {
    console.log('🚀 Starting bulk merge of contributors...\n');
    
    try {
        const { content } = readContributorsList();
        const currentContributors = parseContributors(content.match(/contributors = \[([\s\S]*)\];/)[1]);
        
        console.log(`📊 Current contributors: ${currentContributors.length}`);
        console.log(`📥 New contributors to add: ${newContributors.length}\n`);
        
        if (newContributors.length === 0) {
            console.log('⚠️  No new contributors specified in the newContributors array.');
            console.log('Please add them to the script and run again.');
            return;
        }
        
        let nextId = getNextId(currentContributors);
        const contributorsToAdd = [];
        const skipped = [];
        
        // Process new contributors
        newContributors.forEach(newContrib => {
            if (!contributorExists(currentContributors, newContrib.fullname, newContrib.username)) {
                contributorsToAdd.push({
                    id: nextId++,
                    fullname: newContrib.fullname,
                    username: newContrib.username
                });
                console.log(`✅ Adding: ${newContrib.fullname}`);
            } else {
                skipped.push(newContrib.fullname);
                console.log(`⚠️  Skipping duplicate: ${newContrib.fullname}`);
            }
        });
        
        console.log(`\n📈 Summary:`);
        console.log(`   • Contributors to add: ${contributorsToAdd.length}`);
        console.log(`   • Duplicates skipped: ${skipped.length}`);
        console.log(`   • Total after merge: ${currentContributors.length + contributorsToAdd.length}`);
        
        if (contributorsToAdd.length === 0) {
            console.log('\n❌ No new contributors to add. All were duplicates.');
            return;
        }
        
        // Generate new contributors array
        const allContributors = [...currentContributors, ...contributorsToAdd];
        const formattedContributors = allContributors.map(formatContributor).join(',\n\n');
        
        // Create new file content
        const newContent = `contributors = [
${formattedContributors},

];
`;
        
        // Create backup first
        const backupPath = path.join(__dirname, 'contributors', 'contributorsList.js.backup-' + Date.now());
        fs.writeFileSync(backupPath, content);
        console.log(`\n💾 Backup created: ${path.basename(backupPath)}`);
        
        // Write the updated file
        fs.writeFileSync(path.join(__dirname, 'contributors', 'contributorsList.js'), newContent);
        console.log(`\n✅ Successfully merged ${contributorsToAdd.length} new contributors!`);
        console.log('🎉 Updated contributorsList.js');
        
        console.log('\n📋 Next steps:');
        console.log('1. Review the updated file');
        console.log('2. Test that it works: node -c contributors/contributorsList.js');
        console.log('3. Commit: git add contributors/contributorsList.js');
        console.log('4. Commit: git commit -m "Merge all Hacktoberfest contributors"');
        console.log('5. Push: git push origin master');
        console.log('6. Close all PRs with thank you messages');
        
        return contributorsToAdd;
        
    } catch (error) {
        console.error('❌ Error:', error.message);
        return null;
    }
}

// Run the merge
if (require.main === module) {
    mergeAllContributors();
} 