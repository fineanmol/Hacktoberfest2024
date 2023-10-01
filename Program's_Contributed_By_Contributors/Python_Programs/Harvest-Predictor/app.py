import numpy as np
from flask import Flask, request, jsonify, render_template
import pickle


flask_app = Flask(__name__)
model = pickle.load(open("model_pickle", "rb"))


@flask_app.route("/")
def Home():
    background_image = "static/101608227-paddy-field.jpg"
    return render_template("index.html", background_image=background_image)


@flask_app.route("/predict", methods=["POST"])
def predict():
    float_features = [float(x) for x in request.form.values()]
    features = [np.array(float_features)]
    prediction = model.predict(features)
    return render_template("index.html", prediction_text=" {}".format(prediction))


if __name__ == "__main__":
    flask_app.run(debug=True,host='0.0.0.0')
