
# RayMaze

RayMaze is an engaging maze game where players navigate through 3 levels with progressively challenging mazes. 



## Overview
The game consists of three mazes, each featuring a small map on the left to guide the player through the maze. The doors that lead to the end are colored red, but not all **red** doors lead to the end. Players must quickly find the correct door before the **timer** ends, or they will get blocked. Additionally, in one of the mazes, there is a monster that will cause the player to die if touched. The game is implemented in C and employs **_raycasting_** to visualize the player's movement by casting virtual rays to trace the maze's contours.

## Features

- **Multiple Levels** : Progress through various levels with increasing difficulty.
- **Raycasting Visualization** : Real-time rendering of the maze using raycasting techniques.
- **Mini-Map** : A small map on the left to guide the player through the maze.
- **Red Doors** : Doors leading to the end are colored red, but not all red doors lead to the exit.
- **Timer Challenge** : Find the correct door before the timer ends or get blocked.
- **Monster Encounte** : Avoid the monster to stay alive.


## Control Keys
- **W** : Move forward. (⬆)
- **S** : Move backward.(⬇)
- **A** : Turn left.(⬅)
- **D** : Turn right.(➡)
- **E** : Open the door.




## Technical Aspects
 ###  Raycasting
Raycasting is a rendering technique used to create a **3D** perspective in a **2D map** by projecting rays from a viewpoint, calculating intersections with objects in the scene, and rendering vertical slices based on these intersections to create the illusion of depth.

**How It Works**
- **2D Grid Map** : The basic idea of raycasting involves a 2D square grid map. Each square can have one of two values :
    * **0**: Represents **no wall** and is visually depicted as a black square.
    - **1**: Represents **a wall** and is visually depicted as a white square (4 represents the doors and is depicted as red square).

       ![1000050173 (3)](https://github.com/user-attachments/assets/7d77e2cc-8f10-4830-b8c3-0c9370e88ae9)


- **Ray Generation** :

    - For each vertical stripe on the screen, a ray is cast from the player's position.

    - The direction of the ray is determined by the player's viewing direction and the x-coordinate of the stripe on the screen.
    - The ray progresses through the 2D grid map. It continues moving until it intersects with a wall (a grid cell 1).    

- **Intersection Calculation** : Upon hitting a wall, the distance from the player to the intersection point is calculated. The distance to the wall determines its height on the screen:
    - **Closer Walls**: Appear taller.
    - **Farther Walls**: Appear shorter.

The image above demonstrates rays *(red)* cast from the player's position *(yellow dot)*.

![1000050174 (1)](https://github.com/user-attachments/assets/a1b9c395-c4b8-4a24-99ee-960588f9fb6c)

These rays intersect with white walls in the grid.
The height of each wall on the screen is proportional to its distance from the player, simulating a 3D effect.





## Screenshots
**Maze 1: The Easy Maze**
- **Description:** This is the smallest and simplest maze in the series. It has a straightforward layout with minimal doors, making it the easiest to navigate. The objective is to find the exit without any complex challenges.

    ![Screenshot 2024-08-08 012116](https://github.com/user-attachments/assets/d86eca6d-bd2f-49a7-8f4e-50b5630a8eb5)


**Maze 2: The Medium Maze**
- **Description:** Larger than Maze 1, this maze introduces a new challenge : a **monster** that players must avoid. Navigating through this maze requires both avoiding the monster and solving the door puzzle.

    ![Screenshot 2024-08-08 012643](https://github.com/user-attachments/assets/f010c3a5-810a-434c-a840-701d5452446b)


**Maze 3: The Complex Maze**
- **Description:** The largest and most intricate maze, Maze 3 presents a significant challenge. It features **multiple doors**, but only one of them leads to the exit. Players must carefully explore the maze and choose the correct door to complete the level before the *timer runs out*, adding an extra layer of urgency to the challenge.

    ![Screenshot 2024-08-08 013149](https://github.com/user-attachments/assets/117cd816-c5eb-4c0f-a795-2142800855f3)

  ## Feedback

    If you have any feedback, please reach out at hibasofyan3@gmail.com
