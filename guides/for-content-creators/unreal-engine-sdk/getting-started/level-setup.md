---
description: Infinity Void Unreal Engine SDK - Getting Started
cover: >-
  https://images.unsplash.com/photo-1542751371-adc38448a05e?crop=entropy&cs=tinysrgb&fm=jpg&ixid=MnwxOTcwMjR8MHwxfHNlYXJjaHwzfHxnYW1pbmd8ZW58MHx8fHwxNjYzOTI1MzI5&ixlib=rb-1.2.1&q=80
coverY: 0
---

# Level Setup

Certainly, here's an example of documentation based on the provided instructions for creating a new map and setting up certain gameplay elements:

## New Map and Gameplay Setup Documentation

### Introduction

This documentation provides step-by-step instructions for creating a new map in your game development project and setting up various gameplay elements to enhance the player experience. Follow these steps to create a new map and configure essential elements within it.

### Creating a New Map

#### Step 1: Create a New Map

1. Inside your project's Content folder, create a new folder named "Maps" to organize your map assets.
2. To create a new map, follow these steps:
   * Click on "File" in the menu.
   * Select "New Level."
   * You'll be presented with various options; choose the one that suits your project's needs. For a large world, select "Open World," and for a small scene, choose the "Basic Level" option.
3. After creating your level, ensure that you save it and give it a meaningful name.

#### Step 2: Set Default Server Map

1. In your project settings, navigate to the "Maps and Modes" section.
2. Update the "Server Default Map" setting with the map you've just created. This ensures that your new map is set as the default server map for your project.

### Adding Gameplay Elements

#### Step 3: Add Player Start

1. Open your newly created map.
2. To add a player start point, follow these steps:
   * Choose the "Place Actors" panel.
   * Select "Player Start" from the available options.
   * Place the player start in your scene. This determines where players will spawn in your map.

#### Step 4: Configuring the Crosshair

1. Open the Level Blueprint for your map.
2. Add the following script to ensure that players see a crosshair while playing.

<figure><img src="../../../../.gitbook/assets/crosshair BP.png" alt=""><figcaption></figcaption></figure>

#### Step 5: Adding a Close UI Actor

1. From the Content Browser, select the "Close\_UI" actor.
2. Place it in your scene. The purpose of this actor is to communicate with the frontend to close the loading screen.
3. You can adjust the delay by changing the delay value in the actor's details.

```
Begin Object Class=/Script/BlueprintGraph.K2Node_CallFunction Name="K2Node_CallFunction_0" ExportPath=/Script/BlueprintGraph.K2Node_CallFunction'"/Game/IVTest.IVTest:PersistentLevel.IVTest.EventGraph.K2Node_CallFunction_0"'
   bIsPureFunc=True
   FunctionReference=(MemberParent=/Script/Engine.BlueprintGeneratedClass'"/InfinityVoid/Utils/BP_IVUtils.BP_IVUtils_C"',MemberName="GetIVHUD",MemberGuid=06F449A648217D11423CB2A251219447)
   NodePosX=192
   NodePosY=784
   NodeGuid=BCDCEA264EAE32D15DB4AF9E272DA8C5
   CustomProperties Pin (PinId=0BFE81514E6AD77111522E8142A81212,PinName="self",PinFriendlyName=NSLOCTEXT("K2Node", "Target", "Target"),PinType.PinCategory="object",PinType.PinSubCategory="",PinType.PinSubCategoryObject=/Script/Engine.BlueprintGeneratedClass'"/InfinityVoid/Utils/BP_IVUtils.BP_IVUtils_C"',PinType.PinSubCategoryMemberReference=(),PinType.PinValueType=(),PinType.ContainerType=None,PinType.bIsReference=False,PinType.bIsConst=False,PinType.bIsWeakPointer=False,PinType.bIsUObjectWrapper=False,PinType.bSerializeAsSinglePrecisionFloat=False,DefaultObject="/InfinityVoid/Utils/BP_IVUtils.Default__BP_IVUtils_C",PersistentGuid=00000000000000000000000000000000,bHidden=True,bNotConnectable=False,bDefaultValueIsReadOnly=False,bDefaultValueIsIgnored=False,bAdvancedView=False,bOrphanedPin=False,)
   CustomProperties Pin (PinId=456DA25A4651957BD956A789D1B91774,PinName="__WorldContext",PinType.PinCategory="object",PinType.PinSubCategory="",PinType.PinSubCategoryObject=/Script/CoreUObject.Class'"/Script/CoreUObject.Object"',PinType.PinSubCategoryMemberReference=(),PinType.PinValueType=(),PinType.ContainerType=None,PinType.bIsReference=False,PinType.bIsConst=False,PinType.bIsWeakPointer=False,PinType.bIsUObjectWrapper=False,PinType.bSerializeAsSinglePrecisionFloat=False,PersistentGuid=00000000000000000000000000000000,bHidden=True,bNotConnectable=False,bDefaultValueIsReadOnly=False,bDefaultValueIsIgnored=False,bAdvancedView=False,bOrphanedPin=False,)
   CustomProperties Pin (PinId=A4277DED48ECD9B99C29EB9639EA565F,PinName="AsBP ZEZHUD",Direction="EGPD_Output",PinType.PinCategory="object",PinType.PinSubCategory="",PinType.PinSubCategoryObject=/Script/Engine.BlueprintGeneratedClass'"/InfinityVoid/Core/BP_IVHUD.BP_IVHUD_C"',PinType.PinSubCategoryMemberReference=(),PinType.PinValueType=(),PinType.ContainerType=None,PinType.bIsReference=False,PinType.bIsConst=False,PinType.bIsWeakPointer=False,PinType.bIsUObjectWrapper=False,PinType.bSerializeAsSinglePrecisionFloat=False,LinkedTo=(K2Node_CallFunction_1 8543D4BF4572265A96EF4988A970A8D6,K2Node_Knot_0 32E72135417A7EFAE8486CBDA127D040,),PersistentGuid=00000000000000000000000000000000,bHidden=False,bNotConnectable=False,bDefaultValueIsReadOnly=False,bDefaultValueIsIgnored=False,bAdvancedView=False,bOrphanedPin=False,)
End Object
Begin Object Class=/Script/BlueprintGraph.K2Node_CallFunction Name="K2Node_CallFunction_1" ExportPath=/Script/BlueprintGraph.K2Node_CallFunction'"/Game/IVTest.IVTest:PersistentLevel.IVTest.EventGraph.K2Node_CallFunction_1"'
   FunctionReference=(MemberParent=/Script/CoreUObject.Class'"/Script/InfinityVoid.IVHUD"',MemberName="AddCrosshairMainScreen")
   NodePosX=352
   NodePosY=592
   NodeGuid=204F39D44C925911E922148D2E6F6E24
   CustomProperties Pin (PinId=6CD31E024A38CA63F183EE938F0ABB8E,PinName="execute",PinType.PinCategory="exec",PinType.PinSubCategory="",PinType.PinSubCategoryObject=None,PinType.PinSubCategoryMemberReference=(),PinType.PinValueType=(),PinType.ContainerType=None,PinType.bIsReference=False,PinType.bIsConst=False,PinType.bIsWeakPointer=False,PinType.bIsUObjectWrapper=False,PinType.bSerializeAsSinglePrecisionFloat=False,PersistentGuid=00000000000000000000000000000000,bHidden=False,bNotConnectable=False,bDefaultValueIsReadOnly=False,bDefaultValueIsIgnored=False,bAdvancedView=False,bOrphanedPin=False,)
   CustomProperties Pin (PinId=1844328A47DB1B962B1F9580FF984290,PinName="then",Direction="EGPD_Output",PinType.PinCategory="exec",PinType.PinSubCategory="",PinType.PinSubCategoryObject=None,PinType.PinSubCategoryMemberReference=(),PinType.PinValueType=(),PinType.ContainerType=None,PinType.bIsReference=False,PinType.bIsConst=False,PinType.bIsWeakPointer=False,PinType.bIsUObjectWrapper=False,PinType.bSerializeAsSinglePrecisionFloat=False,LinkedTo=(K2Node_CallFunction_2 7EA428204DA711AA1789F5B2B86A72DB,),PersistentGuid=00000000000000000000000000000000,bHidden=False,bNotConnectable=False,bDefaultValueIsReadOnly=False,bDefaultValueIsIgnored=False,bAdvancedView=False,bOrphanedPin=False,)
   CustomProperties Pin (PinId=8543D4BF4572265A96EF4988A970A8D6,PinName="self",PinFriendlyName=NSLOCTEXT("K2Node", "Target", "Target"),PinType.PinCategory="object",PinType.PinSubCategory="",PinType.PinSubCategoryObject=/Script/CoreUObject.Class'"/Script/InfinityVoid.IVHUD"',PinType.PinSubCategoryMemberReference=(),PinType.PinValueType=(),PinType.ContainerType=None,PinType.bIsReference=False,PinType.bIsConst=False,PinType.bIsWeakPointer=False,PinType.bIsUObjectWrapper=False,PinType.bSerializeAsSinglePrecisionFloat=False,LinkedTo=(K2Node_CallFunction_0 A4277DED48ECD9B99C29EB9639EA565F,),PersistentGuid=00000000000000000000000000000000,bHidden=False,bNotConnectable=False,bDefaultValueIsReadOnly=False,bDefaultValueIsIgnored=False,bAdvancedView=False,bOrphanedPin=False,)
End Object
Begin Object Class=/Script/BlueprintGraph.K2Node_CallFunction Name="K2Node_CallFunction_2" ExportPath=/Script/BlueprintGraph.K2Node_CallFunction'"/Game/IVTest.IVTest:PersistentLevel.IVTest.EventGraph.K2Node_CallFunction_2"'
   FunctionReference=(MemberParent=/Script/CoreUObject.Class'"/Script/InfinityVoid.IVHUD"',MemberName="SetCrosshairVisibility")
   NodePosX=736
   NodePosY=592
   NodeGuid=2E0B01B14096A17A5D8ED1B286C8D1A2
   CustomProperties Pin (PinId=7EA428204DA711AA1789F5B2B86A72DB,PinName="execute",PinType.PinCategory="exec",PinType.PinSubCategory="",PinType.PinSubCategoryObject=None,PinType.PinSubCategoryMemberReference=(),PinType.PinValueType=(),PinType.ContainerType=None,PinType.bIsReference=False,PinType.bIsConst=False,PinType.bIsWeakPointer=False,PinType.bIsUObjectWrapper=False,PinType.bSerializeAsSinglePrecisionFloat=False,LinkedTo=(K2Node_CallFunction_1 1844328A47DB1B962B1F9580FF984290,),PersistentGuid=00000000000000000000000000000000,bHidden=False,bNotConnectable=False,bDefaultValueIsReadOnly=False,bDefaultValueIsIgnored=False,bAdvancedView=False,bOrphanedPin=False,)
   CustomProperties Pin (PinId=5CD0FFCF490D9E9BDB6776B5B0B8B47E,PinName="then",Direction="EGPD_Output",PinType.PinCategory="exec",PinType.PinSubCategory="",PinType.PinSubCategoryObject=None,PinType.PinSubCategoryMemberReference=(),PinType.PinValueType=(),PinType.ContainerType=None,PinType.bIsReference=False,PinType.bIsConst=False,PinType.bIsWeakPointer=False,PinType.bIsUObjectWrapper=False,PinType.bSerializeAsSinglePrecisionFloat=False,PersistentGuid=00000000000000000000000000000000,bHidden=False,bNotConnectable=False,bDefaultValueIsReadOnly=False,bDefaultValueIsIgnored=False,bAdvancedView=False,bOrphanedPin=False,)
   CustomProperties Pin (PinId=C7FFD1C04CD4D83AB73E7FB5B709D92A,PinName="self",PinFriendlyName=NSLOCTEXT("K2Node", "Target", "Target"),PinType.PinCategory="object",PinType.PinSubCategory="",PinType.PinSubCategoryObject=/Script/CoreUObject.Class'"/Script/InfinityVoid.IVHUD"',PinType.PinSubCategoryMemberReference=(),PinType.PinValueType=(),PinType.ContainerType=None,PinType.bIsReference=False,PinType.bIsConst=False,PinType.bIsWeakPointer=False,PinType.bIsUObjectWrapper=False,PinType.bSerializeAsSinglePrecisionFloat=False,LinkedTo=(K2Node_Knot_0 8894E7814F931E2249B42F85E5079A15,),PersistentGuid=00000000000000000000000000000000,bHidden=False,bNotConnectable=False,bDefaultValueIsReadOnly=False,bDefaultValueIsIgnored=False,bAdvancedView=False,bOrphanedPin=False,)
   CustomProperties Pin (PinId=6D676E0D4141CD4B21F3BF81A9BC17CD,PinName="bVisible",PinType.PinCategory="bool",PinType.PinSubCategory="",PinType.PinSubCategoryObject=None,PinType.PinSubCategoryMemberReference=(),PinType.PinValueType=(),PinType.ContainerType=None,PinType.bIsReference=False,PinType.bIsConst=False,PinType.bIsWeakPointer=False,PinType.bIsUObjectWrapper=False,PinType.bSerializeAsSinglePrecisionFloat=False,DefaultValue="true",AutogeneratedDefaultValue="false",PersistentGuid=00000000000000000000000000000000,bHidden=False,bNotConnectable=False,bDefaultValueIsReadOnly=False,bDefaultValueIsIgnored=False,bAdvancedView=False,bOrphanedPin=False,)
End Object
Begin Object Class=/Script/BlueprintGraph.K2Node_Knot Name="K2Node_Knot_0" ExportPath=/Script/BlueprintGraph.K2Node_Knot'"/Game/IVTest.IVTest:PersistentLevel.IVTest.EventGraph.K2Node_Knot_0"'
   NodePosX=672
   NodePosY=816
   NodeGuid=F11F060D4264A193A47798AE01574CEA
   CustomProperties Pin (PinId=32E72135417A7EFAE8486CBDA127D040,PinName="InputPin",PinType.PinCategory="object",PinType.PinSubCategory="",PinType.PinSubCategoryObject=/Script/Engine.BlueprintGeneratedClass'"/InfinityVoid/Core/BP_IVHUD.BP_IVHUD_C"',PinType.PinSubCategoryMemberReference=(),PinType.PinValueType=(),PinType.ContainerType=None,PinType.bIsReference=False,PinType.bIsConst=False,PinType.bIsWeakPointer=False,PinType.bIsUObjectWrapper=False,PinType.bSerializeAsSinglePrecisionFloat=False,LinkedTo=(K2Node_CallFunction_0 A4277DED48ECD9B99C29EB9639EA565F,),PersistentGuid=00000000000000000000000000000000,bHidden=False,bNotConnectable=False,bDefaultValueIsReadOnly=False,bDefaultValueIsIgnored=True,bAdvancedView=False,bOrphanedPin=False,)
   CustomProperties Pin (PinId=8894E7814F931E2249B42F85E5079A15,PinName="OutputPin",Direction="EGPD_Output",PinType.PinCategory="object",PinType.PinSubCategory="",PinType.PinSubCategoryObject=/Script/Engine.BlueprintGeneratedClass'"/InfinityVoid/Core/BP_IVHUD.BP_IVHUD_C"',PinType.PinSubCategoryMemberReference=(),PinType.PinValueType=(),PinType.ContainerType=None,PinType.bIsReference=False,PinType.bIsConst=False,PinType.bIsWeakPointer=False,PinType.bIsUObjectWrapper=False,PinType.bSerializeAsSinglePrecisionFloat=False,LinkedTo=(K2Node_CallFunction_2 C7FFD1C04CD4D83AB73E7FB5B709D92A,),PersistentGuid=00000000000000000000000000000000,bHidden=False,bNotConnectable=False,bDefaultValueIsReadOnly=False,bDefaultValueIsIgnored=False,bAdvancedView=False,bOrphanedPin=False,)
End Object
```

<figure><img src="../../../../.gitbook/assets/delay.png" alt=""><figcaption></figcaption></figure>

#### Step 6: Linking to the Lobby Map

1. Navigate to the "Lobby" map, located in the plugins folder.
2. In the "Outline," select "BP\_InfinityVoidSDK" and go to "Details."
3. In the "Gameplay Level" field, choose the map you've just created. This links your new map to the lobby map.

<figure><img src="../../../../.gitbook/assets/level select.png" alt=""><figcaption></figcaption></figure>

#### Step 7: Adding an Exit Volume (Optional)

* For a more immersive experience, you can add a volume actor called "BP\_Exit." Placing this actor and configuring the volume inside it will allow players to return to the city if they enter this designated area.

### Making Elements Interactable

#### Step 8: Making Elements Interactable

* If you want to make in-game objects interactable, use the "BP\_InteractableBase" actor. Create a child class from it, modify the static mesh within the actor, and add interaction logic to the event graph.
* To add interaction functionality to any other class, like a pawn, add the "IVInterface" to it and follow the same interaction logic.
