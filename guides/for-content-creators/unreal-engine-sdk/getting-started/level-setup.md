# Level Setup

Instructions for creating a new map in your game development project and setting up various gameplay elements to enhance the player experience. Follow these steps to create a new map and configure essential elements within it.

### Creating a New Map

To create a new map, follow these steps:

* Click on "File" in the menu.
* Select "New Level."
* You'll be presented with various options; choose the one that suits your project's needs. For a large world, select "Open World," and for a small scene, choose the "Basic Level" option.

<div>

<figure><img src="../../../../.gitbook/assets/new level.png" alt=""><figcaption></figcaption></figure>

 

<figure><img src="../../../../.gitbook/assets/options.png" alt=""><figcaption></figcaption></figure>

</div>

### Set Default Server Map

In your project settings, navigate to the `Maps and Modes` section.

Update the `Server Default Map` setting with the map you've just created. This ensures that your new map is set as the default server map for your project.

### Adding Player Start

Open your newly created map.

To add a player start point, follow these steps:

* Choose the "Place Actors" panel.
* Select "Player Start" from the available options.
* Place the player start in your scene. This determines where players will spawn in your map.

<div>

<figure><img src="../../../../.gitbook/assets/place actors panel.png" alt=""><figcaption></figcaption></figure>

 

<figure><img src="../../../../.gitbook/assets/player start.png" alt=""><figcaption></figcaption></figure>

</div>

### Adding Crosshair

Open the Level Blueprint for your map.

Add the following script to ensure that players see a crosshair while playing.

{% hint style="info" %}
Crosshair is mandatory if you wish to utilize the default interaction system present in our SDK.
{% endhint %}

<figure><img src="../../../../.gitbook/assets/crosshair BP.png" alt=""><figcaption></figcaption></figure>

Or you can copy and paste this code directly within the event graph of the level blueprint.

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

### Adding a Close UI Actor

1. From the Content Browser navigate to `Plugins` > `Infinity Void Content` > `Utils`, select the `Close_UI` actor.
2. Place it in your scene. The purpose of this actor is to communicate with the frontend to close the loading screen.
3. You can adjust the delay by changing the delay value in the actor's details.

{% hint style="info" %}
If you wish to close the loading screen based on some event you may use the same logic present in the Close\_UI actor.
{% endhint %}

<figure><img src="../../../../.gitbook/assets/delay.png" alt=""><figcaption></figcaption></figure>

### Linking to the Lobby Map

Navigate to the "Lobby" map, located in the plugins folder.

In the Outliner select `BP_InfinityVoidSDK` and go to `Details`.

In the `Gameplay Level` field, choose the map you've just created. This links your new map to the lobby map.

{% hint style="info" %}
Lobby map is the application's default map. This map is visible to players. It only servers the purpose of opening the main level which you create.
{% endhint %}

<figure><img src="../../../../.gitbook/assets/level select.png" alt=""><figcaption></figcaption></figure>

#### Adding an Exit Volume (Optional)

For a more immersive experience, you can add a volume actor called `BP_Exit` by navigating to `Plugins` > `Infinity Void Content` > `Utils`. Placing this actor and configuring the volume inside it will allow players to return to the city if they enter this designated area.
