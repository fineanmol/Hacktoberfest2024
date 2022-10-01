from flask import Flask,render_template,request,redirect
import sqlite3 as sql
import requests

app = Flask(__name__)


@app.route('/',methods=['GET'])
def hello_world():
    return render_template('index.html')


@app.route('/shortener',methods=['GET','POST'])
def short():
    if request.method=='POST':
        longurl = request.form['longurl']
        custom = request.form['custom']
        if not longurl and custom:
            return 'Error <script>alert("Invalid Credentials");</script>'
        if longurl.startswith("http://" or "https://"):
            pass
        else:
            longurl = str("http://"+str(longurl))

        try:
            r = requests.get(longurl)
            if r.status_code == 200:
                pass
            else:
                return 'Invalid URL <script>alert("Invalid URL");</script>'
        except:
            return '''Invalid URL <script>alert("Invalid URL");
            var meta = document.createElement('meta');
		meta.httpEquiv = "REFRESH";
		meta.content = "0;URL=/";
		document.getElementsByTagName('head')[0].appendChild(meta);
            </script>'''

        print longurl
        print custom
        conn = sql.connect('urls.db')
        cursor = conn.cursor()
        #print cursor.execute("SELECT * FROM urls;")

        try:
            cursor.execute("INSERT INTO urls(longurl,custom) VALUES (?,?);", (str(longurl),str(custom)))
        except:
            return '''Invalid/Already existing custom url <script>alert("Invalid/Already existing custom url");
               var meta = document.createElement('meta');
		meta.httpEquiv = "REFRESH";
		meta.content = "0;URL=/";
		document.getElementsByTagName('head')[0].appendChild(meta);
            </script>'''
        conn.commit()
        conn.close()
        url = "http://127.0.0.1:5000/shortener/"+custom

        return 'Live at <a target="_blank" href="'+url+'">'+url+'</a>'
    return ""

@app.route('/shortener/<custom>',methods=['GET','POST'])
def final(custom):

    conn = sql.connect('urls.db')
    cursor = conn.cursor()
    cursor.execute('SELECT * FROM urls WHERE custom=?;', (str(custom),))
    #return_this = cursor.fetchall()
    #return_this = [[str(item) for item in results] for results in cursor.fetchall()]
    for row in cursor.fetchall():
        return_this= row[0]


    print return_this

    return redirect(return_this,code=302)





if __name__ == '__main__':
    app.run(port=5000)
Footer
