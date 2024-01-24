import requests
from pprint import pprint as fprint
import datetime

body = """{
  stopPlace(id: "NSR:StopPlace:610") {
    name
    id
    estimatedCalls(numberOfDepartures: 5, whiteListedModes: [rail]) {
      expectedDepartureTime
      aimedDepartureTime
      destinationDisplay {
        frontText
      }
      serviceJourney {
        line {
          publicCode
          transportMode
        }
      }
    }
  }
}"""


url = "https://api.entur.io/journey-planner/v2/graphql"


response = requests.post(url=url, json={"query": body})
if response.status_code == 200:
    res_sp = response.json()

    current_station = res_sp['data']['stopPlace']['name']
    current_time = datetime.datetime.now().strftime("%H:%M:%S")

    print(f"-- {current_station}--")
    print(f"-- {current_time} --")
    print("")

    for call in res_sp["data"]["stopPlace"]["estimatedCalls"]:
        code = call["serviceJourney"]["line"]["publicCode"]
        end_station = call["destinationDisplay"]["frontText"]

        departure_time = call["expectedDepartureTime"].split("T")[1].split("+")[0]
        dpt = (int(departure_time.split(":")[0]) * 60 + int(departure_time.split(":")[1])) - (int(current_time.split(":")[0]) * 60 + int(current_time.split(":")[1]))

        indlen = 30 - (len(end_station) + len(code))
        if dpt == 0:
            print(f"{code} til {end_station}{indlen * " "}|{5 * " "}Nå")
        else:
            print(f"{code} til {end_station}{indlen * " "}|{5 * " "}{dpt} min")