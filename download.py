"""
Downloads all accepted submissions from LeetCode.
"""
import time
import os
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import NoSuchElementException

USERNAME = 'username'  # <- Replace with your username
PASSWORD = 'password'  # <- Replace with your password
SUBMISSIONS_URL = "https://leetcode.com/submissions/"
PROBLEMS_DIR = "Problems"
PROBLEMS_LIST_FILE = "problems.md"


def update_problems_list(problem_name, problem_link, problem_file_name=None):
    """
    Updates the problems list file containing the problem names and links.
    """

    # TODO: Add difficulty and tags to the problems list file

    filename = problem_file_name if problem_file_name else f"{problem_name}.cpp"

    file_link = f"{PROBLEMS_DIR}/{filename}"

    if not os.path.exists(PROBLEMS_LIST_FILE):
        with open(PROBLEMS_LIST_FILE, 'w', encoding='utf-8') as f:
            f.write("# Problems Table\n\n")
            f.write("| Problem | Solution |\n")
            f.write("| ------- | -------- |\n")

    with open(PROBLEMS_LIST_FILE, 'a', encoding='utf-8') as f:
        f.write(f"| [{problem_name}]({problem_link}) | [{filename}]({file_link}) |\n")


def download_submissions(username, password):
    """
    Downloads submissions from LeetCode.

    Args:
        username (str): The username to login to LeetCode.
        password (str): The password to login to LeetCode.
    """
    driver = webdriver.Firefox()
    driver.get(SUBMISSIONS_URL)

    try:
        # Wait for the login page to load
        time.sleep(5)

        # Login
        username_field = driver.find_element(By.NAME, 'login')
        password_field = driver.find_element(By.NAME, 'password')
        username_field.send_keys(username)
        password_field.send_keys(password)
        password_field.send_keys(Keys.RETURN)

        while True:
            # Wait for redirection to submissions page
            time.sleep(10)

            # Store the links first
            links = []
            existing_filenames = set(os.listdir(PROBLEMS_DIR)) if os.path.exists(PROBLEMS_DIR) else set()

            rows = driver.find_elements(By.XPATH, "//table[contains(@class, 'table')]/tbody/tr")
            for row in rows:
                status = row.find_element(By.XPATH, ".//td[3]").text.strip()
                if "Accepted" in status:
                    link = row.find_element(By.XPATH, ".//td[3]//a").get_attribute('href')
                    problem_name = row.find_element(By.XPATH, ".//td[2]").text.strip().replace(' ', '_').replace('.', '')

                    # Generate a unique filename
                    filename = f"{problem_name}.cpp"
                    version = 1
                    while filename in existing_filenames:
                        filename = f"{problem_name}_{version}.cpp"
                        version += 1

                    # Add the unique filename to the set
                    existing_filenames.add(filename)

                    # Append (link, problem_name, filename) tuple to links
                    links.append((link, problem_name, filename))

            cur_page = SUBMISSIONS_URL

            # Process each link
            for link, problem_name, filename in links:

                driver.get(link)
                time.sleep(10)

                code_lines = driver.find_elements(
                    By.CLASS_NAME, 'ace_line')

                code = "\n".join([line.text for line in code_lines])

                # Create the directory if it doesn't exist
                if not os.path.exists(PROBLEMS_DIR):
                    os.makedirs(PROBLEMS_DIR)

                # TODO: Add difficulty subdirectories

                # Write the code to file
                with open(os.path.join(PROBLEMS_DIR, filename),
                          'w', encoding='utf-8') as f:
                    f.write(code)

                # Update the problems list file
                update_problems_list(problem_name, link, filename)

                # Go back to the submissions list after processing each link
                # to avoid stale element reference error
                driver.get(cur_page)
                WebDriverWait(driver, 20).until(
                    EC.presence_of_element_located(
                        (By.ID, 'submission-list-app'))
                )
                time.sleep(10)  # Wait for page to load; adjust as needed

            try:
                # Look for the "Older" or "Next Page" button/link
                cur_page = driver.find_element(
                    By.XPATH, "//a[@href and contains(., 'Older')]")
                cur_page.click()
                time.sleep(2)  # Wait for page to load; adjust as needed
            except NoSuchElementException:
                # If the "Next Page" link is not found, break from the loop
                break

    except NoSuchElementException as e:
        print(f"A NoSuchElementException occurred: {e}")
    finally:
        driver.quit()


download_submissions(USERNAME, PASSWORD)
