# 3081 Lab 10: Import Assets
_(Due: Thursday, April. 6th, 2023 @ 11:59pm)_

## General Information

### Accessing a Lab Machine

For this assignment, we suggest you use a lab machine in ***Keller Hall 1-250*** or ***Keller Hall 1-262*** ([details](https://cse.umn.edu/cseit/classrooms-labs#cselabs)), as Git is already installed on these machines. You can also access a lab machine remotely using [SSH](https://github.umn.edu/umn-csci-3081-S23/FAQs/blob/main/SSH/README.md) or a web-based service called [VOLE](https://github.umn.edu/umn-csci-3081-S23/FAQs/blob/main/VOLE/README.md). You will use your CSE Labs account to login to the lab machines. If you do not already have an account, create the account following these [instructions](https://wwws.cs.umn.edu/account-management).


**IMPORTANT: Inside the lab machine, only files saved to your home folder (e.g., `/home/kaung006`) will persist across sessions. If you log out, make sure your progress is pushed to GitHub or saved in the home folder.**

**IMPORTANT: One of the reasons you might not be able to log into a lab machine is that you reached your CSE Labs Account disk quota. To free space, please use these [instructions](https://github.umn.edu/umn-csci-3081-S23/FAQs/blob/main/CSE%20Disk%20Quota%20Exceeds/README.md). (In some cases, you might need to SSH into a CSE classroom or lab machine to complete the instructions.)**

## Retrieve Class Materials

1. Clone **public lab10** repo
    ```bash
    git clone https://github.umn.edu/umn-csci-3081-S23/public-lab10
    ```

2. Clone your **private lab10** repo<br>
    *Note: **replace** Team-XXX-X with your lecture section and team number* <br>
    *Example: Team-001-1-lab10*
    ```bash
    git clone git@github.umn.edu:umn-csci-3081-S23/Team-XXX-X-lab10.git
    ```

3. Copy the content of **public lab10** repo into your **private lab10** repo and you can start working inside your private repo. <br>
 **OR** <br>
 You can copy the content of your **private lab09** into your **private lab09** repo if you wish to use your lab09 codes.

### What's in lab10 folder?

<ul>
  <li>  <code>README.md</code>
  <li>  <code>.gitignore</code>
  <li>  <code>app</code> folder, which contains:
    <ul>
      <li>  <code>graph_viewer</code> : producing graph visualization
      <li>  <code>transit_service</code> : visualization
    </ul>
  <li>  <code>libs</code> folder, which contains:
    <ul>
      <li>  <code>routing</code> : finding the paths
      <li>  <code>trainsit</code> : entities properties
    </ul>
  <li>  <code>dependencies</code>
</ul>

## Lab Instructions

### Goal
<hr>
  **The primary goal of this lab is for you to know how to add assets (i.e., models) into the simulation and prepare you for the final project.**
<hr>

## Tasks
| ID | Title | Task Summary Description | Task Deliverable |
| :---: | --- | --- | --- |
| Task 1 | Assets | Add helicopter to the simulation | Source Code |
| Task 2 | Assets | Add human to the simulation | Source Code |
| Task 3 | Create Button | Create button on webpage (front-end) to support the creation of multiple human | HTML and Javascript |
| Task 4 | Assets | Implement your own idea | Source Code |
| Task 5 | Doxygen | Create documentation of the classes/functions that you create | HTML/Source Code |
| Task 6 | Code Styling | Match your code style with Google style guidlines | Source Code |

## Demo
You can view the demo of the final result [here](https://youtu.be/5cmdE6seXvw).

# Tasks
### Task 1 (Helicopter)
Steps:
1. Download helicopter model from either [class github](https://github.umn.edu/umn-csci-3081-S23/shared-upstream/tree/main/Project_Assets) or other sources.
   - *Important: File must be .glb format*
2. Place the helicopter model under `<project>/apps/transit_service/web/assets/model/` folder.
3. Create the `Helicopter` entity class. This class will do nothing except moving from its position toward the destination that is chosen randomly, after it reaches toward its destination, it will choose next random destination again.
   - This helicopter can move freely without using any path (i.e, no need to use Astar, Dijkstra, DFS).
   - XYZ Bounding:
        ```
        -1400 < x < 1500
         240  < y < Infinity
        -800  < z < 800
        ```
4. Add `HelicopterFactory` to the existing composite factory design pattern.
   - type: "helicopter"
5. When the webpage starts to run, it will call the `umn.json` file which can be found under `<project>/apps/transit_service/web/scenes/umn.json`
6. Add new json object inside the umn.json to **create** a helicopter right at the start of the scene with the followings info (Note: replace mesh, position, and scale according to your model's choice):
   ```
    "type": "helicopter",
    "name": "Helicopter",
    "mesh": "assets/model/helicopter.glb",
    "position": [x, y, z],
    "scale": [xScale, yScale, zScale],
    "rotation": [0, 0, 0, 0],
    "direction": [1,0,0],
    "speed": 50.0,
    "offset": [0, 0.6, 0]
   ```
   `mesh` = model file location<br>
   `position` = your choice as long as it's within the map <br>
   `scale` = make it look like real life size (i.e., not too small or too large)
7. If you did all of the steps above correctly, now the helicopter should be created and moving around as soon as you start the webpage.

### Task 2 (Human)
Steps:
1. Download Human model from either [class github](https://github.umn.edu/umn-csci-3081-S23/shared-upstream/tree/main/Project_Assets) or other sources.
   - *Important: File must be .glb format*
2. Place the human model under `<project>/apps/transit_service/web/assets/model/` folder.
3. Create the `Human` entity class. This class will do nothing except moving from its position toward the destination that is chosen randomly, after it reaches toward its destination, it will choose next random destination again.
   - Must use Astar strategy to move around
   - XYZ Bounding:
        ```
        -1400 < x < 1500
         240  < y < Infinity
        -800  < z < 800
        ```
4. Add `HumanFactory` to the existing composite factory design pattern.
   - type: "human"
5. When the webpage starts to run, it will call the `umn.json` file which can be found under `<project>/apps/transit_service/web/scenes/umn.json`
6. Add new json object inside the umn.json to **create** a human right at the start of the scene with the followings info (Note: replace mesh, position, and scale according to your model's choice):
   ```
   "type": "human",
   "name": "Human-OG",
   "mesh": "assets/model/human.glb",
   "position": [498.292, 270, -228.623],
   "scale": [0.005, 0.005, 0.005],
   "rotation": [0, 0, 0, 0],
   "direction": [1,0,0],
   "speed": 10.0,
   "radius": 1.0,
   "start": 2.0,
   "duration": 2.0,
   "offset": [0, -0.5, 0]
   ```
   `mesh` = model file location<br>
   `position` = your choice as long as it's within the map <br>
   `scale` = make it look like real life size (i.e., not too small or too large)
7. If you did all of the steps above correctly, now the human should be created and moving around as soon as you start the webpage.

### Task 3 (Create Button)
Steps:
1. You will need to use some HTML and Javascript for this task.
2. HTML will be use to display the button to the users and Javascript will be use to move the data from the front-end to the back-end.
3. The button will be created under the schedule page which can be found at `<project>\apps\transit_service\web\schedule.html`
4. We want to create the `Add Humans` button below the Schedule Trip. So, first find the location of the `Schedule Trip` button (line 70).
   - Button syntax: `<input type="button" value="Text to Display">`
   - onClick(): When the button is clicked, it will call to the given function here. 
5. Under the schedule trip button, create a button which displays `Add Human` and it will call `addHuman()` function.
6. Currently, the `Schedule Trip` button and `Add Human` button are too close together, we want it to seperate a bit. Add `style="margin-top: 10px;"` inside the existing add helicopter button element. 
   
   Example:
   ```
   <div ... style = "..."></div>
   ```
7. Optional: If you are already pro in the front-end and would like to make cool designs of the button, you are welcome to do so.
8. Inside the script element, create a function which will use the api to send the data to the back-end. The function name must be `addHuman()` to match with step 5. As an guide, check out the `function schedule() {...}` on how to create a function using Javascript.
9. First declare humanID inside the script element.
  ```
  var humanID = 1;
  ```
10. Inside this addHuman() function, first call the api to create an entity with the following json data (you might want to modify the mesh, position, and scale as you see fit):
   ```
   "type": "human",
   "name": "Human-"+humanID,
   "mesh": "assets/model/human.glb",
   "position": [700, 290, 400],
   "scale": [xScale, yScale, zScale],
   "rotation": [0, 0, 0, 0],
   "direction": [1,0,0],
   "speed": 10.0,
   "radius": 1.0,
   "start": 2.0,
   "duration": 2.0,
   "offset": [0, -0.5, 0]
   ```
   `mesh` = model file location<br>
   `scale` = make it look like real life size (i.e., not too small or too large)
9. Add humanID += 1 after you call the api as this will increment the human ID.
10. If you did all of the steps above correctly, now the human will sqawn if you click `Add Human` button.

### Task 4 (Implement your own idea)
For this task, create at least **one** new entity of your own choice and you can decide what you want this entity to do. This entity should **at least** created once when the simulation start. *Be creative as much as possible*.

**Important: Your entity should be doing something.**

Example ideas:
   - High speed jetplane or sports car
   - Kangroo hopping when travelling to the destination
   - Tom and Jerry chasing each other

### Task 5 (Doxygen)
Write Doxygen for all the **NEW** classes you create (public members only). Which in our case for this lab, are as follows:
- Helicopter
- HelicopterFactory
- Human
- HumanFactory

### Task 6 (Code Style)
Match your new code's style with Google Code Styling guide. Which in our case for this lab, is as follow:
- Helicopter
- HelicopterFactory
- Human
- HumanFactory

## Final Submission

To submit your assignment, post on the Gradescope assignment "Lab 10: Import Assets" your team repo link and the final commit ID for your submission.
Click [here](https://github.umn.edu/umn-csci-3081-S23/FAQs/blob/main/Commit%20ID/README.md) to see how to get commit id.
