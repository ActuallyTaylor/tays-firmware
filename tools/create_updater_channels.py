
# class File(object):
#     url: String
#     target: String
#     type: String

# class Version(object):
#     version: String
#     changelog: String
#     timestamp: Number
#     files: [File]

# class Channel(object):
#     id: String
#     title: String
#     description: String
#     versions: [Version]

#     def __init__(self):
#         self.x = 1
#         self.y = 2
import json

def main():
    with open('update.json') as f:
        data = json.load(f)
        copy = data.copy()
        channels = copy["channels"]

        for channel in channels:
            id = channel["id"]
            title = channel["title"]
            description = channel["description"]
        



if __name__ == "__main__":
    main()