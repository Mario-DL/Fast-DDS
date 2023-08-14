// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file ImageData.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "ImageData.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>


#define ImageDataMsg_max_cdr_typesize 472ULL;
#define ImageFormatMsg_max_cdr_typesize 16ULL;

#define ImageDataMsg_max_key_cdr_typesize 0ULL;
#define ImageFormatMsg_max_key_cdr_typesize 0ULL;


ImageFormatMsg::ImageFormatMsg()
{
    // unsigned long m_width
    m_width = 0;
    // unsigned long m_height
    m_height = 0;
    // unsigned long m_stride
    m_stride = 0;
    // PixelFormatEnum m_format
    m_format = ::FORMAT_1;

}

ImageFormatMsg::~ImageFormatMsg()
{




}

ImageFormatMsg::ImageFormatMsg(
        const ImageFormatMsg& x)
{
    m_width = x.m_width;
    m_height = x.m_height;
    m_stride = x.m_stride;
    m_format = x.m_format;
}

ImageFormatMsg::ImageFormatMsg(
        ImageFormatMsg&& x) noexcept 
{
    m_width = x.m_width;
    m_height = x.m_height;
    m_stride = x.m_stride;
    m_format = x.m_format;
}

ImageFormatMsg& ImageFormatMsg::operator =(
        const ImageFormatMsg& x)
{

    m_width = x.m_width;
    m_height = x.m_height;
    m_stride = x.m_stride;
    m_format = x.m_format;

    return *this;
}

ImageFormatMsg& ImageFormatMsg::operator =(
        ImageFormatMsg&& x) noexcept
{

    m_width = x.m_width;
    m_height = x.m_height;
    m_stride = x.m_stride;
    m_format = x.m_format;

    return *this;
}

bool ImageFormatMsg::operator ==(
        const ImageFormatMsg& x) const
{

    return (m_width == x.m_width && m_height == x.m_height && m_stride == x.m_stride && m_format == x.m_format);
}

bool ImageFormatMsg::operator !=(
        const ImageFormatMsg& x) const
{
    return !(*this == x);
}

size_t ImageFormatMsg::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    static_cast<void>(current_alignment);
    return ImageFormatMsg_max_cdr_typesize;
}

size_t ImageFormatMsg::getCdrSerializedSize(
        const ImageFormatMsg& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);



    return current_alignment - initial_alignment;
}

void ImageFormatMsg::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_width;
    scdr << m_height;
    scdr << m_stride;
    scdr << (uint32_t)m_format;

}

void ImageFormatMsg::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_width;
    dcdr >> m_height;
    dcdr >> m_stride;
    {
        uint32_t enum_value = 0;
        dcdr >> enum_value;
        m_format = (PixelFormatEnum)enum_value;
    }

}

/*!
 * @brief This function sets a value in member width
 * @param _width New value for member width
 */
void ImageFormatMsg::width(
        uint32_t _width)
{
    m_width = _width;
}

/*!
 * @brief This function returns the value of member width
 * @return Value of member width
 */
uint32_t ImageFormatMsg::width() const
{
    return m_width;
}

/*!
 * @brief This function returns a reference to member width
 * @return Reference to member width
 */
uint32_t& ImageFormatMsg::width()
{
    return m_width;
}

/*!
 * @brief This function sets a value in member height
 * @param _height New value for member height
 */
void ImageFormatMsg::height(
        uint32_t _height)
{
    m_height = _height;
}

/*!
 * @brief This function returns the value of member height
 * @return Value of member height
 */
uint32_t ImageFormatMsg::height() const
{
    return m_height;
}

/*!
 * @brief This function returns a reference to member height
 * @return Reference to member height
 */
uint32_t& ImageFormatMsg::height()
{
    return m_height;
}

/*!
 * @brief This function sets a value in member stride
 * @param _stride New value for member stride
 */
void ImageFormatMsg::stride(
        uint32_t _stride)
{
    m_stride = _stride;
}

/*!
 * @brief This function returns the value of member stride
 * @return Value of member stride
 */
uint32_t ImageFormatMsg::stride() const
{
    return m_stride;
}

/*!
 * @brief This function returns a reference to member stride
 * @return Reference to member stride
 */
uint32_t& ImageFormatMsg::stride()
{
    return m_stride;
}

/*!
 * @brief This function sets a value in member format
 * @param _format New value for member format
 */
void ImageFormatMsg::format(
        PixelFormatEnum _format)
{
    m_format = _format;
}

/*!
 * @brief This function returns the value of member format
 * @return Value of member format
 */
PixelFormatEnum ImageFormatMsg::format() const
{
    return m_format;
}

/*!
 * @brief This function returns a reference to member format
 * @return Reference to member format
 */
PixelFormatEnum& ImageFormatMsg::format()
{
    return m_format;
}



size_t ImageFormatMsg::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    static_cast<void>(current_alignment);
    return ImageFormatMsg_max_key_cdr_typesize;
}

bool ImageFormatMsg::isKeyDefined()
{
    return false;
}

void ImageFormatMsg::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
}


ImageDataMsg::ImageDataMsg()
{
    // unsigned long m_cameraId
    m_cameraId = 0;
    // unsigned long long m_frameNumber
    m_frameNumber = 0;
    // unsigned long m_frameTag
    m_frameTag = 0;
    // double m_exposureDuration
    m_exposureDuration = 0.0;
    // double m_gain
    m_gain = 0.0;
    // double m_readoutDurationSeconds
    m_readoutDurationSeconds = 0.0;
    // long long m_captureTimestampNs
    m_captureTimestampNs = 0;
    // long long m_captureTimestampInProcessingClockDomainNs
    m_captureTimestampInProcessingClockDomainNs = 0;
    // long long m_arrivalTimestampNs
    m_arrivalTimestampNs = 0;
    // long long m_processingStartTimestampNs
    m_processingStartTimestampNs = 0;
    // double m_temperatureDegC
    m_temperatureDegC = 0.0;
    // ImageFormatMsg m_imageFormat

    // string m_videoCodecName
    m_videoCodecName ="";
    // unsigned long m_imageBufferSize
    m_imageBufferSize = 0;
    // sequence<octet> m_data


}

ImageDataMsg::~ImageDataMsg()
{















}

ImageDataMsg::ImageDataMsg(
        const ImageDataMsg& x)
{
    m_cameraId = x.m_cameraId;
    m_frameNumber = x.m_frameNumber;
    m_frameTag = x.m_frameTag;
    m_exposureDuration = x.m_exposureDuration;
    m_gain = x.m_gain;
    m_readoutDurationSeconds = x.m_readoutDurationSeconds;
    m_captureTimestampNs = x.m_captureTimestampNs;
    m_captureTimestampInProcessingClockDomainNs = x.m_captureTimestampInProcessingClockDomainNs;
    m_arrivalTimestampNs = x.m_arrivalTimestampNs;
    m_processingStartTimestampNs = x.m_processingStartTimestampNs;
    m_temperatureDegC = x.m_temperatureDegC;
    m_imageFormat = x.m_imageFormat;
    m_videoCodecName = x.m_videoCodecName;
    m_imageBufferSize = x.m_imageBufferSize;
    m_data = x.m_data;
}

ImageDataMsg::ImageDataMsg(
        ImageDataMsg&& x) noexcept 
{
    m_cameraId = x.m_cameraId;
    m_frameNumber = x.m_frameNumber;
    m_frameTag = x.m_frameTag;
    m_exposureDuration = x.m_exposureDuration;
    m_gain = x.m_gain;
    m_readoutDurationSeconds = x.m_readoutDurationSeconds;
    m_captureTimestampNs = x.m_captureTimestampNs;
    m_captureTimestampInProcessingClockDomainNs = x.m_captureTimestampInProcessingClockDomainNs;
    m_arrivalTimestampNs = x.m_arrivalTimestampNs;
    m_processingStartTimestampNs = x.m_processingStartTimestampNs;
    m_temperatureDegC = x.m_temperatureDegC;
    m_imageFormat = std::move(x.m_imageFormat);
    m_videoCodecName = std::move(x.m_videoCodecName);
    m_imageBufferSize = x.m_imageBufferSize;
    m_data = std::move(x.m_data);
}

ImageDataMsg& ImageDataMsg::operator =(
        const ImageDataMsg& x)
{

    m_cameraId = x.m_cameraId;
    m_frameNumber = x.m_frameNumber;
    m_frameTag = x.m_frameTag;
    m_exposureDuration = x.m_exposureDuration;
    m_gain = x.m_gain;
    m_readoutDurationSeconds = x.m_readoutDurationSeconds;
    m_captureTimestampNs = x.m_captureTimestampNs;
    m_captureTimestampInProcessingClockDomainNs = x.m_captureTimestampInProcessingClockDomainNs;
    m_arrivalTimestampNs = x.m_arrivalTimestampNs;
    m_processingStartTimestampNs = x.m_processingStartTimestampNs;
    m_temperatureDegC = x.m_temperatureDegC;
    m_imageFormat = x.m_imageFormat;
    m_videoCodecName = x.m_videoCodecName;
    m_imageBufferSize = x.m_imageBufferSize;
    m_data = x.m_data;

    return *this;
}

ImageDataMsg& ImageDataMsg::operator =(
        ImageDataMsg&& x) noexcept
{

    m_cameraId = x.m_cameraId;
    m_frameNumber = x.m_frameNumber;
    m_frameTag = x.m_frameTag;
    m_exposureDuration = x.m_exposureDuration;
    m_gain = x.m_gain;
    m_readoutDurationSeconds = x.m_readoutDurationSeconds;
    m_captureTimestampNs = x.m_captureTimestampNs;
    m_captureTimestampInProcessingClockDomainNs = x.m_captureTimestampInProcessingClockDomainNs;
    m_arrivalTimestampNs = x.m_arrivalTimestampNs;
    m_processingStartTimestampNs = x.m_processingStartTimestampNs;
    m_temperatureDegC = x.m_temperatureDegC;
    m_imageFormat = std::move(x.m_imageFormat);
    m_videoCodecName = std::move(x.m_videoCodecName);
    m_imageBufferSize = x.m_imageBufferSize;
    m_data = std::move(x.m_data);

    return *this;
}

bool ImageDataMsg::operator ==(
        const ImageDataMsg& x) const
{

    return (m_cameraId == x.m_cameraId && m_frameNumber == x.m_frameNumber && m_frameTag == x.m_frameTag && m_exposureDuration == x.m_exposureDuration && m_gain == x.m_gain && m_readoutDurationSeconds == x.m_readoutDurationSeconds && m_captureTimestampNs == x.m_captureTimestampNs && m_captureTimestampInProcessingClockDomainNs == x.m_captureTimestampInProcessingClockDomainNs && m_arrivalTimestampNs == x.m_arrivalTimestampNs && m_processingStartTimestampNs == x.m_processingStartTimestampNs && m_temperatureDegC == x.m_temperatureDegC && m_imageFormat == x.m_imageFormat && m_videoCodecName == x.m_videoCodecName && m_imageBufferSize == x.m_imageBufferSize && m_data == x.m_data);
}

bool ImageDataMsg::operator !=(
        const ImageDataMsg& x) const
{
    return !(*this == x);
}

size_t ImageDataMsg::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    static_cast<void>(current_alignment);
    return ImageDataMsg_max_cdr_typesize;
}

size_t ImageDataMsg::getCdrSerializedSize(
        const ImageDataMsg& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += ImageFormatMsg::getCdrSerializedSize(data.imageFormat(), current_alignment);
    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + data.videoCodecName().size() + 1;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    if (data.data().size() > 0)
    {
        current_alignment += (data.data().size() * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);
    }




    return current_alignment - initial_alignment;
}

void ImageDataMsg::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_cameraId;
    scdr << m_frameNumber;
    scdr << m_frameTag;
    scdr << m_exposureDuration;
    scdr << m_gain;
    scdr << m_readoutDurationSeconds;
    scdr << m_captureTimestampNs;
    scdr << m_captureTimestampInProcessingClockDomainNs;
    scdr << m_arrivalTimestampNs;
    scdr << m_processingStartTimestampNs;
    scdr << m_temperatureDegC;
    scdr << m_imageFormat;
    scdr << m_videoCodecName.c_str();
    scdr << m_imageBufferSize;
    scdr << m_data;

}

void ImageDataMsg::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_cameraId;
    dcdr >> m_frameNumber;
    dcdr >> m_frameTag;
    dcdr >> m_exposureDuration;
    dcdr >> m_gain;
    dcdr >> m_readoutDurationSeconds;
    dcdr >> m_captureTimestampNs;
    dcdr >> m_captureTimestampInProcessingClockDomainNs;
    dcdr >> m_arrivalTimestampNs;
    dcdr >> m_processingStartTimestampNs;
    dcdr >> m_temperatureDegC;
    dcdr >> m_imageFormat;
    dcdr >> m_videoCodecName;
    dcdr >> m_imageBufferSize;
    dcdr >> m_data;
}

/*!
 * @brief This function sets a value in member cameraId
 * @param _cameraId New value for member cameraId
 */
void ImageDataMsg::cameraId(
        uint32_t _cameraId)
{
    m_cameraId = _cameraId;
}

/*!
 * @brief This function returns the value of member cameraId
 * @return Value of member cameraId
 */
uint32_t ImageDataMsg::cameraId() const
{
    return m_cameraId;
}

/*!
 * @brief This function returns a reference to member cameraId
 * @return Reference to member cameraId
 */
uint32_t& ImageDataMsg::cameraId()
{
    return m_cameraId;
}

/*!
 * @brief This function sets a value in member frameNumber
 * @param _frameNumber New value for member frameNumber
 */
void ImageDataMsg::frameNumber(
        uint64_t _frameNumber)
{
    m_frameNumber = _frameNumber;
}

/*!
 * @brief This function returns the value of member frameNumber
 * @return Value of member frameNumber
 */
uint64_t ImageDataMsg::frameNumber() const
{
    return m_frameNumber;
}

/*!
 * @brief This function returns a reference to member frameNumber
 * @return Reference to member frameNumber
 */
uint64_t& ImageDataMsg::frameNumber()
{
    return m_frameNumber;
}

/*!
 * @brief This function sets a value in member frameTag
 * @param _frameTag New value for member frameTag
 */
void ImageDataMsg::frameTag(
        uint32_t _frameTag)
{
    m_frameTag = _frameTag;
}

/*!
 * @brief This function returns the value of member frameTag
 * @return Value of member frameTag
 */
uint32_t ImageDataMsg::frameTag() const
{
    return m_frameTag;
}

/*!
 * @brief This function returns a reference to member frameTag
 * @return Reference to member frameTag
 */
uint32_t& ImageDataMsg::frameTag()
{
    return m_frameTag;
}

/*!
 * @brief This function sets a value in member exposureDuration
 * @param _exposureDuration New value for member exposureDuration
 */
void ImageDataMsg::exposureDuration(
        double _exposureDuration)
{
    m_exposureDuration = _exposureDuration;
}

/*!
 * @brief This function returns the value of member exposureDuration
 * @return Value of member exposureDuration
 */
double ImageDataMsg::exposureDuration() const
{
    return m_exposureDuration;
}

/*!
 * @brief This function returns a reference to member exposureDuration
 * @return Reference to member exposureDuration
 */
double& ImageDataMsg::exposureDuration()
{
    return m_exposureDuration;
}

/*!
 * @brief This function sets a value in member gain
 * @param _gain New value for member gain
 */
void ImageDataMsg::gain(
        double _gain)
{
    m_gain = _gain;
}

/*!
 * @brief This function returns the value of member gain
 * @return Value of member gain
 */
double ImageDataMsg::gain() const
{
    return m_gain;
}

/*!
 * @brief This function returns a reference to member gain
 * @return Reference to member gain
 */
double& ImageDataMsg::gain()
{
    return m_gain;
}

/*!
 * @brief This function sets a value in member readoutDurationSeconds
 * @param _readoutDurationSeconds New value for member readoutDurationSeconds
 */
void ImageDataMsg::readoutDurationSeconds(
        double _readoutDurationSeconds)
{
    m_readoutDurationSeconds = _readoutDurationSeconds;
}

/*!
 * @brief This function returns the value of member readoutDurationSeconds
 * @return Value of member readoutDurationSeconds
 */
double ImageDataMsg::readoutDurationSeconds() const
{
    return m_readoutDurationSeconds;
}

/*!
 * @brief This function returns a reference to member readoutDurationSeconds
 * @return Reference to member readoutDurationSeconds
 */
double& ImageDataMsg::readoutDurationSeconds()
{
    return m_readoutDurationSeconds;
}

/*!
 * @brief This function sets a value in member captureTimestampNs
 * @param _captureTimestampNs New value for member captureTimestampNs
 */
void ImageDataMsg::captureTimestampNs(
        int64_t _captureTimestampNs)
{
    m_captureTimestampNs = _captureTimestampNs;
}

/*!
 * @brief This function returns the value of member captureTimestampNs
 * @return Value of member captureTimestampNs
 */
int64_t ImageDataMsg::captureTimestampNs() const
{
    return m_captureTimestampNs;
}

/*!
 * @brief This function returns a reference to member captureTimestampNs
 * @return Reference to member captureTimestampNs
 */
int64_t& ImageDataMsg::captureTimestampNs()
{
    return m_captureTimestampNs;
}

/*!
 * @brief This function sets a value in member captureTimestampInProcessingClockDomainNs
 * @param _captureTimestampInProcessingClockDomainNs New value for member captureTimestampInProcessingClockDomainNs
 */
void ImageDataMsg::captureTimestampInProcessingClockDomainNs(
        int64_t _captureTimestampInProcessingClockDomainNs)
{
    m_captureTimestampInProcessingClockDomainNs = _captureTimestampInProcessingClockDomainNs;
}

/*!
 * @brief This function returns the value of member captureTimestampInProcessingClockDomainNs
 * @return Value of member captureTimestampInProcessingClockDomainNs
 */
int64_t ImageDataMsg::captureTimestampInProcessingClockDomainNs() const
{
    return m_captureTimestampInProcessingClockDomainNs;
}

/*!
 * @brief This function returns a reference to member captureTimestampInProcessingClockDomainNs
 * @return Reference to member captureTimestampInProcessingClockDomainNs
 */
int64_t& ImageDataMsg::captureTimestampInProcessingClockDomainNs()
{
    return m_captureTimestampInProcessingClockDomainNs;
}

/*!
 * @brief This function sets a value in member arrivalTimestampNs
 * @param _arrivalTimestampNs New value for member arrivalTimestampNs
 */
void ImageDataMsg::arrivalTimestampNs(
        int64_t _arrivalTimestampNs)
{
    m_arrivalTimestampNs = _arrivalTimestampNs;
}

/*!
 * @brief This function returns the value of member arrivalTimestampNs
 * @return Value of member arrivalTimestampNs
 */
int64_t ImageDataMsg::arrivalTimestampNs() const
{
    return m_arrivalTimestampNs;
}

/*!
 * @brief This function returns a reference to member arrivalTimestampNs
 * @return Reference to member arrivalTimestampNs
 */
int64_t& ImageDataMsg::arrivalTimestampNs()
{
    return m_arrivalTimestampNs;
}

/*!
 * @brief This function sets a value in member processingStartTimestampNs
 * @param _processingStartTimestampNs New value for member processingStartTimestampNs
 */
void ImageDataMsg::processingStartTimestampNs(
        int64_t _processingStartTimestampNs)
{
    m_processingStartTimestampNs = _processingStartTimestampNs;
}

/*!
 * @brief This function returns the value of member processingStartTimestampNs
 * @return Value of member processingStartTimestampNs
 */
int64_t ImageDataMsg::processingStartTimestampNs() const
{
    return m_processingStartTimestampNs;
}

/*!
 * @brief This function returns a reference to member processingStartTimestampNs
 * @return Reference to member processingStartTimestampNs
 */
int64_t& ImageDataMsg::processingStartTimestampNs()
{
    return m_processingStartTimestampNs;
}

/*!
 * @brief This function sets a value in member temperatureDegC
 * @param _temperatureDegC New value for member temperatureDegC
 */
void ImageDataMsg::temperatureDegC(
        double _temperatureDegC)
{
    m_temperatureDegC = _temperatureDegC;
}

/*!
 * @brief This function returns the value of member temperatureDegC
 * @return Value of member temperatureDegC
 */
double ImageDataMsg::temperatureDegC() const
{
    return m_temperatureDegC;
}

/*!
 * @brief This function returns a reference to member temperatureDegC
 * @return Reference to member temperatureDegC
 */
double& ImageDataMsg::temperatureDegC()
{
    return m_temperatureDegC;
}

/*!
 * @brief This function copies the value in member imageFormat
 * @param _imageFormat New value to be copied in member imageFormat
 */
void ImageDataMsg::imageFormat(
        const ImageFormatMsg& _imageFormat)
{
    m_imageFormat = _imageFormat;
}

/*!
 * @brief This function moves the value in member imageFormat
 * @param _imageFormat New value to be moved in member imageFormat
 */
void ImageDataMsg::imageFormat(
        ImageFormatMsg&& _imageFormat)
{
    m_imageFormat = std::move(_imageFormat);
}

/*!
 * @brief This function returns a constant reference to member imageFormat
 * @return Constant reference to member imageFormat
 */
const ImageFormatMsg& ImageDataMsg::imageFormat() const
{
    return m_imageFormat;
}

/*!
 * @brief This function returns a reference to member imageFormat
 * @return Reference to member imageFormat
 */
ImageFormatMsg& ImageDataMsg::imageFormat()
{
    return m_imageFormat;
}
/*!
 * @brief This function copies the value in member videoCodecName
 * @param _videoCodecName New value to be copied in member videoCodecName
 */
void ImageDataMsg::videoCodecName(
        const std::string& _videoCodecName)
{
    m_videoCodecName = _videoCodecName;
}

/*!
 * @brief This function moves the value in member videoCodecName
 * @param _videoCodecName New value to be moved in member videoCodecName
 */
void ImageDataMsg::videoCodecName(
        std::string&& _videoCodecName)
{
    m_videoCodecName = std::move(_videoCodecName);
}

/*!
 * @brief This function returns a constant reference to member videoCodecName
 * @return Constant reference to member videoCodecName
 */
const std::string& ImageDataMsg::videoCodecName() const
{
    return m_videoCodecName;
}

/*!
 * @brief This function returns a reference to member videoCodecName
 * @return Reference to member videoCodecName
 */
std::string& ImageDataMsg::videoCodecName()
{
    return m_videoCodecName;
}
/*!
 * @brief This function sets a value in member imageBufferSize
 * @param _imageBufferSize New value for member imageBufferSize
 */
void ImageDataMsg::imageBufferSize(
        uint32_t _imageBufferSize)
{
    m_imageBufferSize = _imageBufferSize;
}

/*!
 * @brief This function returns the value of member imageBufferSize
 * @return Value of member imageBufferSize
 */
uint32_t ImageDataMsg::imageBufferSize() const
{
    return m_imageBufferSize;
}

/*!
 * @brief This function returns a reference to member imageBufferSize
 * @return Reference to member imageBufferSize
 */
uint32_t& ImageDataMsg::imageBufferSize()
{
    return m_imageBufferSize;
}

/*!
 * @brief This function copies the value in member data
 * @param _data New value to be copied in member data
 */
void ImageDataMsg::data(
        const std::vector<uint8_t>& _data)
{
    m_data = _data;
}

/*!
 * @brief This function moves the value in member data
 * @param _data New value to be moved in member data
 */
void ImageDataMsg::data(
        std::vector<uint8_t>&& _data)
{
    m_data = std::move(_data);
}

/*!
 * @brief This function returns a constant reference to member data
 * @return Constant reference to member data
 */
const std::vector<uint8_t>& ImageDataMsg::data() const
{
    return m_data;
}

/*!
 * @brief This function returns a reference to member data
 * @return Reference to member data
 */
std::vector<uint8_t>& ImageDataMsg::data()
{
    return m_data;
}


size_t ImageDataMsg::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    static_cast<void>(current_alignment);
    return ImageDataMsg_max_key_cdr_typesize;
}

bool ImageDataMsg::isKeyDefined()
{
    return false;
}

void ImageDataMsg::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
}

