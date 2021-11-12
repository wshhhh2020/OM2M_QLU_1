# 🚀 A Smart Automatic Pet Feeder Based on OM2M WEB

## 😺 Pet


#### 👑 Core functions
At present, the system can automatically generate `text boxes`, `drop-down boxes (with data association)`, `date controls (date and date and time controls)`, `radio buttons`, `file uploads (tables can be Display pictures directly) `etc, convenient and comfortable.


#### 🚂 Software Architecture
Java backend：SpringBoot 2.1.0 + Mybatis-plus+ hutool Toolkit+ Apache poi

Front page：Vue2.0 + ElementUI + Jquery + tinymce（Rich text plugin）

database：Mysql5.7+

**Note: JDK chooses `1.8` version, Mysql chooses `5.7` version**

The front and back ends are separated, and the page can be deployed separately, placed in the static folder of the project by default, and then accessed together with the end project.


#### 🚁 Installation tutorial

1. Use idea to open the Pet folder and import the project

2. Configure maven, download project dependencies

   ![image-20211111170031850](readme.assets/image-20211111170031850.png)

3. Create a new database pet, execute pet.sql

   ![image-20211111170208470](readme.assets/image-20211111170208470.png)
   ![](https://www.hualigs.cn/image/60a4645016b23.jpg)

4. Modify the database password in application.yml

   ![image-20211111171154046](readme.assets/image-20211111171154046.png)

   

5. After the project dependencies are downloaded, run Application directly to start SpringBoot

   ![image-20211111171240416](readme.assets/image-20211111171240416.png)

6. running result  

   ![image-20211111171402356](readme.assets/image-20211111171402356.png)

#### 🛸 Instructions for use

1. Login page please visit：http://localhost:9999/page/end/login.html
2. account：admin，password：admin

#### 🎨 Screenshot of the interface

login

![image-20211111172738995](readme.assets/image-20211111172738995.png)

register

![image-20211111172747919](readme.assets/image-20211111172747919.png)

项目主页

![image-20211111172802296](readme.assets/image-20211111172802296.png)

![image-20211111172809041](readme.assets/image-20211111172809041.png)

User Interface

![image-20211111173034412](readme.assets/image-20211111173034412.png)![image-20211111173038766](C:\Users\zk\AppData\Roaming\Typora\typora-user-images\image-20211111173038766.png)

User MGMT

![image-20211111173103466](readme.assets/image-20211111173103466.png)

Role MGMT	

![image-20211111173130697](readme.assets/image-20211111173130697.png)

Authority MGMT

![image-20211111173200466](readme.assets/image-20211111173200466.png)

Notification MGMT

![image-20211111173208287](readme.assets/image-20211111173208287.png)



# 🐱device_main



#### 🛫 Project introduction

Project purpose : Remote intelligent pet feeding machine

A programming language : Arduino

Development board : ESP8266



#### ✨ Main functions 

- [ ] To connect to the Internet
- [ ] Get weight
- [ ] Acquisition of ultrasonic ranging
- [ ] Access to water
- [ ] Obtaining temperature and humidity
- [ ] Control of steering gear
- [ ] Control the water pump
- [ ] Upload data



#### 🛒 Library  support

```c#
<ESP8266WiFi.h>

<SimpleDHT.h>

<Timer.h>

<Servo.h>

<HX711.h>
```




#### 🚁 Develop board pins

![See the source image](https://www.soulfree.cn/wp-content/uploads/2020/04/2020042309435240-1024x651.png)



#### 🛸 Sensors used

1. SG90

   ![See the source image](https://tse1-mm.cn.bing.net/th/id/OIP-C.z1yStKTYGyRzV2W7nDx6twHaHa?pid=ImgDet&rs=1)

2. HX711

   ![See the source image](https://tse3-mm.cn.bing.net/th/id/OIP-C.TIBzYkRt5bzs-58UtdwC4gHaHa?pid=ImgDet&rs=1)

3. HC - SR04

   ![See the source image](https://tse3-mm.cn.bing.net/th/id/OIP-C.X9wxxxMW-dKFYNtgJrUwPQHaHa?pid=ImgDet&rs=1)

4. DHT11

   ![See the source image](https://tse2-mm.cn.bing.net/th/id/OIP-C.uDVZ6gE4U3FMOevrL5gaZAHaHa?pid=ImgDet&rs=1)

   

   







