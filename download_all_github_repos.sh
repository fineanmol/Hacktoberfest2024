

download_repos()
 {  user_name="$1"  temp_dir=$(mktemp -d -q /tmp/repo_archive_XXXXXX)  if [ $? -ne 0 ]; then      echo "$0: Can't create a temp dir!"      exit 1  fi    echo "Using the following temp dir: $temp_dir"  cd "$temp_dir" &&   virtualenv env &&  source env/bin/activate &&  pip install ghcloneall &&  ghcloneall --init --user "$user_name" &&  ghcloneall &&   deactivate &&  cd ~  destination="$user_name""_repo_archive.tar"  tar -cvf "$destination" "$temp_dir"  rm -rf "$temp_dir"  echo "All repositories of $user_name have been written to $destination"}
main() {    if [[ $# -ne 1 ]]; then        echo "Usage: download_all_github_repos.sh [github_username]"        exit 1    fi
    download_repos "$1"}
main "$@"

