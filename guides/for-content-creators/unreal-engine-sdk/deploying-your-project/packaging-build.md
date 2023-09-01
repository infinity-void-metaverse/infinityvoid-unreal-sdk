# Packaging Build

In the journey towards deploying your project on Infinity Void, the initial stride involves packaging your creation. Within the context of Unreal Engine, "packaging" refers to the process of compiling all the necessary assets, code, and resources into a standalone executable or a set of files that can be easily shared and executed on other systems.

Efficiency is key during packaging. We strongly recommend aiming for the smallest possible package size while ensuring all required components are included. Infinity Void supports Windows builds, and a lean package size contributes to a smoother user experience and faster downloads for others.

**Project Settings Preparation**

Before initiating the packaging process, make sure your project settings align with the guidelines outlined in the [installation guide](../getting-started/02.-plugin-installation-guide.md). This ensures that your project is optimized and well-prepared for packaging. A well-configured project setting is fundamental for producing a polished and functional package.&#x20;

**Optimizing Package Size**

To further optimize the package size, consider packaging only the specific levels or maps required for your intended deployment. By doing so, you're ensuring that only the assets necessary for those levels are included, thus reducing the overall package size. Unreal Engine offers a convenient feature to achieve this:

1. Navigate to **Project Settings**.
2. Under **Maps & Modes**, locate **Maps to be Included in the Package**.
3. Select only the maps or levels that are relevant for deployment.

This approach not only minimizes package size but also streamlines the loading process, enhancing the overall experience for users accessing your creation on Infinity Void.

By carefully adhering to these packaging principles, you're setting the stage for a refined and efficient deployment process. A well-packaged project not only enhances user interaction but also contributes to the seamless integration of your creation within Infinity Void's metaverse.

If you require assistance packaging your projects you could check Epic Games [Official Documentation](https://docs.unrealengine.com/5.2/en-US/packaging-unreal-engine-projects/) for packaging projects.&#x20;
