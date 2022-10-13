const bcrypt = require('bcrypt')

/**
 *Generate and return _hashedText_ from given `plainText` (string) with 10 salt rounds
 */
function generateHash(plainText) {
    try {
        const hashedText = bcrypt.hashSync(plainText, 8, (hashError, hash) => {
            if (hashError) throw new Error(hashError)
            return hash
        })
        return hashedText
    } catch (hashError) {
        console.log(hashError)
        return
    }
}

/**
 *return true or false depending on the comparison between given `plainText` and its' `hashedText` (both in strings)
 */
function validateHash(plainText, hashedText) {
    try {
        const isPasswordMatches = bcrypt.compareSync(plainText, hashedText, (hashError, isPasswordMatch) => {
            if (hashError) throw new Error(hashError)
            return isPasswordMatch
        })
        return isPasswordMatches
    } catch (hashError) {
        console.log(hashError)
        return
    }
}

module.exports = { generateHash, validateHash }