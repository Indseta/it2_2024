import clink as c
from flask import Flask, render_template
import os

app = Flask(__name__)

template_dir = os.path.abspath("../templates")
static_dir = os.path.abspath("../src/static")
app = Flask(__name__, template_folder=template_dir, static_folder=static_dir)

@app.route("/")
def index():
    return render_template("index.html")

def main():
	app.run(debug=True)

if __name__ == "__main__":
    main()