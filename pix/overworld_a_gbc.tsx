<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.4" tiledversion="1.4.3" name="Overworld A (gbc)" tilewidth="16" tileheight="16" tilecount="32" columns="8">
 <image source="overworld_a_gbc.png" width="128" height="64"/>
 <terraintypes>
  <terrain name="grass" tile="0"/>
  <terrain name="tree" tile="12"/>
 </terraintypes>
 <tile id="0" terrain="0,0,0,0"/>
 <tile id="1" terrain="0,0,0,0" probability="0.01"/>
 <tile id="2" terrain="0,0,0,0" probability="0.1"/>
 <tile id="3" terrain="0,0,0,0" probability="0.3"/>
 <tile id="4" terrain="0,0,0,0" probability="0.2"/>
 <tile id="8" terrain="0,0,0,1">
  <properties>
   <property name="collision" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="9" terrain="0,0,1,0">
  <properties>
   <property name="collision" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="10" terrain="1,0,0,1">
  <properties>
   <property name="collision" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="11" terrain="0,1,1,0">
  <properties>
   <property name="collision" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="12" terrain="0,1,0,0">
  <properties>
   <property name="collision" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="13" terrain="1,0,0,0">
  <properties>
   <property name="collision" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="14" terrain="0,0,0,0" probability="0">
  <properties>
   <property name="collision" type="bool" value="true"/>
   <property name="toRight" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="15" terrain="0,0,0,0" probability="0"/>
 <tile id="16">
  <properties>
   <property name="collision" type="bool" value="true"/>
   <property name="read" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="17">
  <properties>
   <property name="collision" type="bool" value="true"/>
   <property name="permanent" type="bool" value="true"/>
   <property name="toRight" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="18">
  <properties>
   <property name="collision" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="23">
  <properties>
   <property name="door" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="24">
  <properties>
   <property name="collision" type="bool" value="true"/>
   <property name="read" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="25">
  <properties>
   <property name="collision" type="bool" value="true"/>
   <property name="move" type="bool" value="true"/>
  </properties>
 </tile>
</tileset>
