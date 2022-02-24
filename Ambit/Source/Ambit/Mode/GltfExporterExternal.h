//   Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//  
//   Licensed under the Apache License, Version 2.0 (the "License").
//   You may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//  
//       http://www.apache.org/licenses/LICENSE-2.0
//  
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

#pragma once

#include "Exporters/GLTFLevelExporter.h"
#include "Serialization/BufferArchive.h"

#include "Ambit/Mode/GltfExporterExternalInterface.h"

#include "GltfExporterExternal.generated.h"


/**
 * Class that forwards all Ambit function calls to the external GLTF Exporter plugin.
 */
UCLASS()
class UGltfExporterExternal : public UObject, public IGltfExporterExternalInterface
{
    GENERATED_BODY()
public:
    UGltfExporterExternal();

    /** @inheritDoc */
    bool DoesExporterExist() override;

    /** @inheritDoc */
    bool ExportBinary(UWorld* World, FBufferArchive& Buffer) override;

    /** @inheritDoc */
    bool WriteToFile(FBufferArchive& Buffer, const FString& Filename) override;

private:
    UGLTFLevelExporter* Exporter;
};