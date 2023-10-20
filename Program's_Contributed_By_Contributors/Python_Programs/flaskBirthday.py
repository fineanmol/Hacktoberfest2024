from flask import Flask, render_template, request, redirect
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__, static_folder='static')

# code for database starts from here
app.config['SQLALCHEMY_DATABASE_URI'] = "sqlite:///birthday.db"
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)

class Birthday(db.Model):
    # table columns are specified here
    sno = db.Column(db.Integer, primary_key=True)
    user_id = db.Column(db.String(200), nullable=False)
    birthday = db.Column(db.String(500), nullable=False)

    # this basically displays stuff
    def __repr__(self) -> str:
        return f"{self.user_id} - {self.birthday}"

@app.route('/', methods=['GET', 'POST'])
def form():
    # this is the main code
    if request.method == 'POST':
        # get data of id and date by this method
        user_id = request.form['id']
        birthdate = request.form['date']
        # create object of Birthday and do the following
        birthday = Birthday(user_id=user_id, birthday=birthdate)
        db.session.add(birthday)
        db.session.commit()
        # Redirect to a different route (GET route) after processing the form data
        return redirect('/show')

    birthdays = Birthday.query.all()
    # the line birthdays = birthdays is the line where we send the data to html
    return render_template('form.html', birthdays=birthdays)

# todo render template
@app.route('/show')
def products():
    birthday = Birthday.query.all()
    return 'this is products page'

if __name__ == "__main__":
    # To solve the error, set up an application context
    with app.app_context():
        # Create all tables defined in the models
        db.create_all()
    
    app.run(host="0.0.0.0", port=5000, debug=True)