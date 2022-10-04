export const generateRandomNumber = ({passwordLength,withNumbers}) => {
    let chars = 'abcdefghijklmnopqrstuvwxyz!@#$%^&*()ABCDEFGHIJKLMNOPQRSTUVWXYZ';
    if (withNumbers) {
        chars += '0123456789';
    }
    let password = '';
    for (let i = 0; i <= passwordLength; i++) {
        const randomNumber = Math.floor(Math.random() * chars.length);
        password += chars.substring(randomNumber, randomNumber + 1);
    }
    return password;
}