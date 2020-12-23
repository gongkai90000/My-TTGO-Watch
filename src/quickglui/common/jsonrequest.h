/****
 * QuickGLUI - Quick Graphical LVLGL-based User Interface development library
 * Copyright  2020  Skurydin Alexey
 * http://github.com/anakod
 * All QuickGLUI project files are provided under the MIT License.
 ****/

#ifndef JSONREQUEST_H
#define JSONREQUEST_H

#include "ArduinoJson.h"
#include "hardware/json_psram_allocator.h"

class JsonRequest : public SpiRamJsonDocument
{
public:
  JsonRequest(size_t maxJsonBufferSize);
  ~JsonRequest();

  bool process(const char* url);

  int httpCode() { return httpcode; }
  DeserializationError getDeserializationError() { return dsError; }

  tm completedAt() { return timeStamp; }
  String fromatCompletedAt(const char* format);
  String errorString();

protected:
  int httpcode = -1;
  time_t now;
  struct tm timeStamp;
  DeserializationError dsError;
};

#endif

