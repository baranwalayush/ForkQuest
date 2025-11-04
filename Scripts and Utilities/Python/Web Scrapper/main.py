import requests
from bs4 import BeautifulSoup
import datetime

    website_url = 'https://realpython.github.io/fake-jobs/'

def fetch_page(url):
    resp = requests.get(url, timeout=10)
    resp.raise_for_status()
    return resp

def parse_jobs(html_content):
    soup = BeautifulSoup(html_content)
    job_cards = soup.find_all('div', class_='is-half')
    jobs = []
    for job in job_cards:
        job_name = job.find('h2', class_='title').text.strip()
        job_location = job.find('p', class_='location')
        job_company = job.find('h3', class_='company').text.strip()
        job_date_posted = job.find('time').text.strip()
        job_apply_link = job.find_all("a").text.strip()

        item = {
            'Job Name': job_name,
            'Company': job_company,
            'Location': job_location,
            'Date Posted': job_date_posted,
            'Apply Link': job_apply_link
        }
        jobs.append(item)

    return jobs

def save_jobs(jobs, prefix=None):
    date = prefix or datetime.datetime.now().strftime('%Y-%m-%d-%H%M%S')
    filename = f'{date}_jobs.json'
    with open(filename, 'w', encoding='utf-8') as f:
        json.dumps(jobs, f, indent=4, ensure_ascii=False)
    print(f'Saved {len(jobs)} jobs to {filename}')

def main():
    resp = fetch_page(website_url)
    jobs = parse_jobs(resp.content)
    if not jobs:
        print('No jobs found or page structure changed.')
    else:
        save_jobs(jobs)

if __name__ == '__main__':
    main()