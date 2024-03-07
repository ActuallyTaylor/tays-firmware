import json
import os
import hashlib
import json

DIST_DIRECTORY = ".././dist/f7"
UPDATER_URL = "PLACEHOLDER"


def main():
    directory = os.fsencode(DIST_DIRECTORY)
    data = []

    for file in os.listdir(directory):
        filename = os.fsdecode(file)
        sha256 = hashlib.sha256(filename.encode('utf-8')).hexdigest()
        type = filename.replace(".", "_")

        data.append(
            {
                "url": f"{UPDATER_URL}/{filename}",
                "target": "f7",
                "type": type,
                "sha256": sha256,
            }
        )

        with open('files.json', 'w') as f:
            json.dump(data, f)


if __name__ == "__main__":
    main()
