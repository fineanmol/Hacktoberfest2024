import requests

# Replace with your GitHub token
#put your github token , you'll get from github 
GITHUB_TOKEN = 'your_github_token'

# Repository details (owner/repo)
OWNER = 'repository_owner'  
REPO = 'repository_name'   

def get_repo_watchers(owner, repo, token):
    url = f"https://api.github.com/repos/{owner}/{repo}"
    headers = {
        'Authorization': f'token {token}'
    }
    response = requests.get(url, headers=headers)

    if response.status_code == 200:
        data = response.json()
        return data['subscribers_count'] 
    else:
        print(f"Error: {response.status_code} - {response.json().get('message', '')}")
        return None

if __name__ == "__main__":
    watchers_count = get_repo_watchers(OWNER, REPO, GITHUB_TOKEN)
    if watchers_count is not None:
        print(f"Number of watchers for {OWNER}/{REPO}: {watchers_count}")
