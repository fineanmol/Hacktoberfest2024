#!/usr/bin/env node

/**
 * Script to merge all Hacktoberfest PRs for contributorsList.js
 * This script helps collect all new contributors from PRs and merges them systematically
 */

const fs = require('fs');
const path = require('path');

// Read the current contributors list
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

// Parse contributors from the array content
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

// Get the next available ID
function getNextId(contributors) {
    const ids = contributors.map(c => c.id);
    return Math.max(...ids) + 1;
}

// Check if contributor already exists
function contributorExists(contributors, fullname, username) {
    return contributors.some(c => 
        c.fullname.toLowerCase() === fullname.toLowerCase() || 
        c.username === username
    );
}

// Format contributor object for the file
function formatContributor(contributor) {
    return `  {
    id: ${contributor.id},
    fullname: "${contributor.fullname}",
    username: "${contributor.username}",
  }`;
}

// Main function to add new contributors
function addNewContributors(newContributors) {
    try {
        const { content } = readContributorsList();
        const currentContributors = parseContributors(content.match(/contributors = \[([\s\S]*)\];/)[1]);
        
        let nextId = getNextId(currentContributors);
        const contributorsToAdd = [];
        
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
                console.log(`⚠️  Skipping duplicate: ${newContrib.fullname}`);
            }
        });
        
        if (contributorsToAdd.length === 0) {
            console.log('No new contributors to add.');
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
        
        // Write the updated file
        fs.writeFileSync(path.join(__dirname, 'contributors', 'contributorsList.js'), newContent);
        console.log(`\n✅ Successfully added ${contributorsToAdd.length} new contributors!`);
        console.log('Updated contributorsList.js');
        
        return contributorsToAdd;
        
    } catch (error) {
        console.error('Error:', error.message);
        return null;
    }
}

// Fix ID sequencing (optional utility)
function fixIdSequencing() {
    try {
        const { content } = readContributorsList();
        const contributors = parseContributors(content.match(/contributors = \[([\s\S]*)\];/)[1]);
        
        // Re-assign sequential IDs
        contributors.forEach((contributor, index) => {
            contributor.id = index + 1;
        });
        
        const formattedContributors = contributors.map(formatContributor).join(',\n\n');
        const newContent = `contributors = [
${formattedContributors},

];
`;
        
        fs.writeFileSync(path.join(__dirname, 'contributors', 'contributorsList.js'), newContent);
        console.log('✅ Fixed ID sequencing successfully!');
        
    } catch (error) {
        console.error('Error fixing IDs:', error.message);
    }
}

// Example usage and instructions
function printUsageInstructions() {
    console.log(`
📋 HACKTOBERFEST PR MERGER SCRIPT

This script helps you merge all PRs systematically. Here's how to use it:

STEP 1: Collect new contributors from all open PRs
   Manually copy the contributor objects from each PR and add them to the newContributors array below.

STEP 2: Run the script
   node merge_prs_script.js

STEP 3: (Optional) Fix ID sequencing
   If you want sequential IDs, uncomment the fixIdSequencing() call below.

Example new contributors format:
const newContributors = [
    { fullname: "John Doe", username: "https://github.com/johndoe" },
    { fullname: "Jane Smith", username: "https://github.com/janesmith" },
    // Add more contributors here...
];
`);
}

// =============================================================================
// MAIN EXECUTION
// =============================================================================

// ADD NEW CONTRIBUTORS HERE - COPY FROM YOUR OPEN PRS
const newContributors = [
    // Example format - replace with actual contributors from your PRs:
    // { fullname: "Contributor Name", username: "https://github.com/username" },
    
    // TODO: Add contributors from your open PRs here
];

// Run the script
if (require.main === module) {
    printUsageInstructions();
    
    if (newContributors.length === 0) {
        console.log('\n⚠️  No new contributors specified. Please add them to the newContributors array in this script.');
    } else {
        addNewContributors(newContributors);
    }
    
    // Uncomment the line below if you want to fix ID sequencing:
    // fixIdSequencing();
}

module.exports = { addNewContributors, fixIdSequencing, parseContributors }; 