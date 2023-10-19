// api/QuizApi.js

export async function fetchQuizData(difficulty: string) {
  const url = `https://opentdb.com/api.php?amount=10&category=18&difficulty=${difficulty}&type=multiple&encode=url3986`;

  try {
    const res = await fetch(url);
    const data = await res.json();
    return data.results;
  } catch (error) {
    throw new Error('Failed to fetch quiz data');
  }
}
