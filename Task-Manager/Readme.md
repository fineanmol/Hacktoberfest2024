# Task Manager 

Basic Task Manager web app that was build using flask micro-framework and this repo work with ```python-V3.6+```

## Introduction 
This web application uses the flask backend with sql-alchemy to crud db for adding and removing tasks 

- where the route update will update the task that you have already created.
- The route delete will delete the task once you clic delete 

## Installation

Go to your terminal/bash and clone this repository using the following link. \
<a href='#'>Clone Here.</a>

### Creating Environment 

#### Using Pip
    1. Install Virtual Environment using following command:
        pip install virtualenv
    2. Open the terminal in the project directory and run:
        virtualenv env
    3. run the following command to activate created venv
       .\env\Scripts\activate
    4. Install the following dependencies by running:
       pip install -r requirements.txt

#### Using Conda 
    1. Create a new conda environment by following command:
       conda create -n <name of env>
    2. Install pip in conda env by following command:
       conda install -c anaconda pip
    3. Install the requirements by running:
       pip install -r requirements.txt

# Languages Used

- <a href=''>Python</a>
- <a href=''>html</a>
- <a href=''>css</a>   

### Bug Reports
Please raise an issue regarding any source code compilation or interpretation errors.

## Finally Let's get it live

After activating your evn's and installing dependencies run the following command that will make website run on local host 

    python app.py


### This server will start on port 5000 by default. You can change this in <a href=''>app.py</a> by changing the following line to this:

    if __name__ == "__main__":
        app.run(debug=True, port=<desired port>)
