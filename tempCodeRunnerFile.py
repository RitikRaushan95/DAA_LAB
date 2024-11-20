import requests
from bs4 import BeautifulSoup

# Define the profile URL
profile_url = "https://www.qwiklabs.com/public_profiles/9185b20d-1cd1-4a04-918a-5e3e5db899ba"

# Get the profile page content
response = requests.get(profile_url)
soup = BeautifulSoup(response.content, 'html.parser')

# Find the section that lists skill badges
badge_section = soup.find_all("div", class_="public-profile-badge-card")

# Count the badges
number_of_badges = len(badge_section)

print(f"The user has {number_of_badges} skill badges.")
