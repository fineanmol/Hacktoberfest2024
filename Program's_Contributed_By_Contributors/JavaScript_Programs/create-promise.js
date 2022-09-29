export function createPromise(secret) {
    const delay = (0.5 + Math.random() * 2) * 1000;
    return new Promise((resolve, reject) => {
      setTimeout(() => {
        if (secret === "hacktoberfest") {
          resolve();
        } else {
          reject(new Error('Wrong secret!'));
        }
      }, delay);
    });
  }
  