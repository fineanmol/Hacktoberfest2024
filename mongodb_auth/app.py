from flask import Flask,render_template,url_for,request,session,redirect
import pymongo
import bcrypt


app=Flask(__name__)

def conn():
     myclient=pymongo.MongoClient("mongodb+srv://<username>:<password>@cluster0.gjpbh.mongodb.net/?retryWrites=true&w=majority")
     mydb=myclient["pymongoAuth"]
     collection=mydb["table1"]
     return collection

mycol=conn()
#print(mycol)

@app.route('/')
def index():
    #print(request.form.get('email'))
    if request.form.get('email') in session:
        return 'You are logged in as ' + session['email']
    return render_template('index.html')


@app.route('/login',methods=['POST','GET'])
def login():
    #print(request.method)
    if request.method == 'POST':
        email=request.form.get('email')
        password=request.form.get('password')
        search={"EMAIL":{"$eq":email}}
        #print(email, password)
        a=mycol.find_one(search)
        #print(a)
        if a is not None:
            if a['EMAIL'] == email and bcrypt.checkpw(password.encode(),bcrypt.hashpw(password.encode(),bcrypt.gensalt())):
                print('matched')
                return 'logged in'
            else:
                return 'not logged in'
        #print('no match')
        return 'no match'
    return render_template('login.html')


@app.route('/register',methods=['POST','GET'])
def register():
    if request.method == "POST":
        email=request.form.get('email')
        password=request.form.get('password')
        search={"EMAIL":{"$eq":email}}
        a=mycol.find_one(search)
        #print(a)
        if a is None:
            hashedpassword=bcrypt.hashpw(password.encode('utf-8'), bcrypt.gensalt())
            list={"EMAIL": email, "PASSWORD": hashedpassword}
            mycol.insert_one(list)
            return redirect(url_for('index'))
        return render_template('error.html')
    return render_template('register.html')


if __name__ == '__main__':
    app.run(debug=True)