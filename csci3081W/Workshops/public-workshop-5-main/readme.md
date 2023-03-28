# Workshop 5 (Docker)
## Prerequisites
As mentioned in a canvas announcement, you should already have Docker installed, as well as an account on Docker Hub
If you haven't already, visit https://hub.docker.com, and create an account with your UMN email.  When this is done, type this command in your terminal and put in your login credentials:
```
docker login
```
From here on, make sure your actual docker daemon is running.  To start it, just open up the Docker app and it should automatically run the daemon.

## Relevant Commands
This workshop introduces a lot of new concepts and commands, so I created a cheat sheet that goes somewhat in-depth on all the commands you may (or may not) need to complete this workshop.

You can find this cheat sheet [here](https://github.umn.edu/umn-csci-3081-S23/public-workshop-5/blob/main/cheatsheet.md).

## Checkpoint 1 - Running a Docker Image
To make sure everything works properly on your end, try typing:
```bash
docker run --rm -d -p 80:80 docker/getting-started
```
It may say that it's unable to find the image locally, that's fine as long as it still pulls the image down.

Check to see that your container is running with:
```bash
docker ps
```

If there's a container listed, then that means everything works!  You can now end this container process with:
```bash
docker kill <CONTAINER ID>
```
`<CONTAINER ID>` can be copied from the result of your previous `docker ps` call

## Checkpoint 2 - Writing the Dockerfile
In this repository, we've provided a `Dockerfile` containing a bit of setup code and a couple comments for guidance.  You're tasked will adding the last few necessary instructions to allow for the creation of a runnable docker image.

The instructions you will need are as follows:
```Dockerfile
RUN <command>     # allows you to run any linux command like you 
                  # would on a labs machine (if using ubuntu image)

COPY <src> <dest> # copies files on local computer to specified 
                  # location in our docker image

WORKDIR <path>    # changes the directory in the docker image 
                  # (similar to how "cd" works in linux)

CMD [ "list", "of", "args" ] # command the container executes when
                             # launching our built image
```
A more detailed description of these instructions can be found in this [cheat sheet](https://github.umn.edu/umn-csci-3081-S23/public-workshop-5/blob/main/cheatsheet.md).

**WARNING**: For any mac users with M1 or M2 chips, make sure to swap the `FROM` instruction at the top of the `Dockerfile` (mentioned in Dockerfile comments).

## Checkpoint 3 - Building the Docker Image
To build a docker image, you must navigate to the directory containing your Dockerfile, then run:
```bash
docker build -t <image_name> <path_to_files>
```

This call invokes the commands outlined in the Dockerfile and builds our image.  The `-t` flag specifies that we want to name our image, and `<path_to_files>` is the relative file path that will be used in our Dockerfile.  Since our Dockerfile is in the root of our project, and we just want to copy this whole project onto our docker image, `<path_to_file>` will always just be `.`

The command you should use to build your image is:
```bash
docker build -t <docker_username>/drone_sim .
```
The naming convention for this image MUST start with your docker username followed by '/', this is the only way (that i'm aware of) Docker will allow you to push your image up to Docker Hub for the workshop 5 submission.

For example, if my docker username was "corey123", then my image name would be "corey123/drone_sim" and my build command is:
```bash
docker build -t corey123/drone_sim .
```

If you get errors during the build process, you may need to tweak your `Dockerfile`.  It could also be the case that your `Dockerfile` is in the wrong folder relative to your project, or you're not in the same directory as your `Dockerfile`.

## Checkpoint 4 - Running the Docker Image
Once you've made the necessary changes to the Dockerfile, and your image builds without issue, it's finally time to see if it works.

The command you will use to run the docker image is:
```bash
docker run --rm -it -p <local_port>:<container_port> <image_name>
```
For the specifics of each flag this command uses, you can see a detailed description of each one used in the cheat sheet [here](https://github.umn.edu/umn-csci-3081-S23/public-workshop-5/blob/main/cheatsheet.md).

If your having trouble terminating your docker container, you can hit `CTRL`+`P`+`Q` to detach your container, then type `docker ps -q | xargs docker kill` to actually terminate it.

## Submission - Deploying Image to Docker Hub
Once you've verified that your image works, you can push your image up to Docker Hub with the following command:
```bash
docker push <image_name>
```

And assuming your image name starts with your docker username followed by a '/', it should successfully send it up to Docker Hub (after about 30-60 sec)

The last thing you need to do before submitting your link on canvas is to add a readme explaining how to run the image.  This readme can be added easily by going to the Docker Hub link to your image and clicking the little pencil icon.

**MAKE SURE YOU ADD A README FOR FULL POINTS!!**
