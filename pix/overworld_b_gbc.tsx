<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.4" tiledversion="1.4.3" name="Overworld B (gbc)" tilewidth="16" tileheight="16" tilecount="32" columns="8">
 <image source="overworld_b_gbc.png" width="128" height="64"/>
 <terraintypes>
  <terrain name="sand" tile="0"/>
  <terrain name="tree" tile="12"/>
  <terrain name="water" tile="26"/>
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
 <tile id="24" terrain="2,2,2,2">
  <properties>
   <property name="collision" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="25" terrain="2,2,2,2" probability="0.01">
  <properties>
   <property name="collision" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="26" terrain="2,2,2,2" probability="0.1">
  <properties>
   <property name="collision" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="27" terrain="0,0,2,2">
  <properties>
   <property name="collision" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="28" terrain="0,0,0,2">
  <properties>
   <property name="collision" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="29" terrain="0,0,2,0">
  <properties>
   <property name="collision" type="bool" value="true"/>
  </properties>
 </tile>
 <tile id="30">
  <properties>
   <property name="collision" type="bool" value="true"/>
  </properties>
 </tile>
 <wangsets>
  <wangset name="water" tile="-1">
   <wangedgecolor name="sand" color="#f6d32d" tile="-1" probability="1"/>
   <wangedgecolor name="water" color="#1c71d8" tile="-1" probability="1"/>
   <wangtile tileid="0" wangid="0x1010101"/>
   <wangtile tileid="1" wangid="0x1010101"/>
   <wangtile tileid="2" wangid="0x1010101"/>
   <wangtile tileid="3" wangid="0x1010101"/>
   <wangtile tileid="4" wangid="0x1010101"/>
   <wangtile tileid="14" wangid="0x1010101"/>
   <wangtile tileid="15" wangid="0x1010101"/>
   <wangtile tileid="24" wangid="0x2020202"/>
   <wangtile tileid="25" wangid="0x2020202"/>
   <wangtile tileid="26" wangid="0x2020202"/>
   <wangtile tileid="27" wangid="0x2020201"/>
   <wangtile tileid="28" wangid="0x1020201"/>
   <wangtile tileid="29" wangid="0x2020101"/>
   <wangtile tileid="30" wangid="0x1020101"/>
  </wangset>
 </wangsets>
</tileset>
