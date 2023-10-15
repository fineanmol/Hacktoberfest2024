import click
import time
import json
from selenium import webdriver
from selenium.webdriver.common.by import By

@click.command()
@click.option("--link",prompt="target link:",help="target post link")
@click.option("--write",prompt="add email and pass in acc.json:",help="add email and pass in acc.json")

def target(link):
    click.echo(f"target {link} set")
    time.sleep(1)
    click.echo("3 sec..")
    time.sleep(1)
    click.echo("2 sec..")
    time.sleep(1)
    click.echo("1 sec..\nattck started...")
    like(link)


def like(target_link):

    ###browser setting

    options=webdriver.FirefoxOptions()
    options.headless=True

    ####target
    target=target_link

    #json file
    with open("acc.json","r") as acc:
        data=json.load(acc)

    #file open for every acc
    for i in data['acc']:

        usr=i["email"]
        pass_=i["pass"]
    
        browser = webdriver.Firefox(options=options)

        browser.get('http://facebook.com/')

        time.sleep(3)
        browser.find_element(By.ID,'email').send_keys(usr)
        browser.find_element(By.ID,'pass').send_keys(pass_)
        btn=browser.find_element(By.CSS_SELECTOR,'button').click()
        time.sleep(3)
        print(f"${i['id']} log in...")

        browser.get(target)

        time.sleep(3)
        browser.find_element(By.XPATH, '//span[contains(text(),"Like")]').click()
        time.sleep(2)
        browser.find_element(By.CSS_SELECTOR, 'div.x1pi30zi:nth-child(5) > div:nth-child(1) > span:nth-child(1) > div:nth-child(1) > div:nth-child(1) > div:nth-child(1) > svg:nth-child(1) > g:nth-child(2) > image:nth-child(1)').click()
        time.sleep(2)
        browser.find_element(By.XPATH, '/html/body/div[1]/div/div[1]/div/div[2]/div[5]/div[2]/div/div/div[1]/div[1]/div/div/div/div/div/div/div/div/div[1]/div/div/div[1]/div[2]/div/div[5]/div/div[1]/div[1]/div/i').click()
        time.sleep(2)
        print(f"${i['id']} log out")
        browser.quit()



if __name__=="__main__":
    target()


