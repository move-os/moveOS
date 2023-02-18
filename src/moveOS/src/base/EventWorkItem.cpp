#include "inc/base/MEventWorkItem.h"

#include "src/_internal_inc/macros.h"


moveOS::base::MSimplestEventWorkItem::MSimplestEventWorkItem(simplest_func workFunc)
{
  this->workFunc = workFunc;
  this->nextWorkItem = nullptr;
}

void moveOS::base::MSimplestEventWorkItem::executeSelf()
{
  if (this->workFunc != nullptr)
  {
    this->workFunc();
  }
}

void moveOS::base::MSimplestEventWorkItem::executeChain()
{
  if (this->workFunc != nullptr)
  {
    this->workFunc();
  }

  if (this->nextWorkItem != nullptr)
  {
    this->nextWorkItem->executeChain();
  }
}





moveOS::base::MSimpleEventWorkItem::MSimpleEventWorkItem(code_ret_simple_func workFunc)
{
  this->workFunc = workFunc;
  this->nextWorkItem = nullptr;
}

void moveOS::base::MSimpleEventWorkItem::executeSelf()
{
  if (this->workFunc != nullptr)
  {
    this->workFunc();
  }
}

void moveOS::base::MSimpleEventWorkItem::executeChain()
{
  if (this->workFunc != nullptr)
  {
    if (this->workFunc() == MEventWorkItemResult::KEEP_CHAINING)
    {
      if (this->nextWorkItem != nullptr)
      {
        this->nextWorkItem->executeChain();
      }
    }
  }
}





moveOS::base::MByteDataEventWorkItem::MByteDataEventWorkItem(byte_data_handler_func workFunc)
{
  this->workFunc = workFunc;
  this->nextWorkItem = nullptr;
}

void moveOS::base::MByteDataEventWorkItem::executeSelf(byte data)
{
  if (this->workFunc != nullptr)
  {
    this->workFunc(data);
  }
}

void moveOS::base::MByteDataEventWorkItem::executeChain(byte data)
{
  if (this->workFunc != nullptr)
  {
    if (this->workFunc(data) == MEventWorkItemResult::KEEP_CHAINING)
    {
      if (this->nextWorkItem != nullptr)
      {
        this->nextWorkItem->executeChain(data);
      }
    }
  }
}





moveOS::base::MDataEventWorkItem::MDataEventWorkItem(data_handler_func workFunc)
{
  this->workFunc = workFunc;
  this->nextWorkItem = nullptr;
}

void moveOS::base::MDataEventWorkItem::executeSelf(byte* data, uint16 length)
{
  if (this->workFunc != nullptr)
  {
    this->workFunc(data, length);
  }
}

void moveOS::base::MDataEventWorkItem::executeChain(byte* data, uint16 length)
{
  if (this->workFunc != nullptr)
  {
    if (this->workFunc(data, length) == MEventWorkItemResult::KEEP_CHAINING)
    {
      if (this->nextWorkItem != nullptr)
      {
        this->nextWorkItem->executeChain(data, length);
      }
    }
  }
}





moveOS::base::MTcpDataEventWorkItem::MTcpDataEventWorkItem(tcp_server_packet_handler_func workFunc)
{
  this->workFunc = workFunc;
  this->nextWorkItem = nullptr;
}

void moveOS::base::MTcpDataEventWorkItem::executeSelf(
  const unsigned char* rcvBuff, const unsigned int rcvBuffSize,
  unsigned char* txnBuff, const unsigned int txnBuffSize, unsigned int& txnBuffTotalBytesWritten,
  const packet_info* receivedFrom)
{
  if (this->workFunc != nullptr)
  {
    this->workFunc(rcvBuff, rcvBuffSize, txnBuff, txnBuffSize, txnBuffTotalBytesWritten, receivedFrom);
  }
}

void moveOS::base::MTcpDataEventWorkItem::executeChain(
  const unsigned char* rcvBuff, const unsigned int rcvBuffSize,
  unsigned char* txnBuff, const unsigned int txnBuffSize, unsigned int& txnBuffTotalBytesWritten,
  const packet_info* receivedFrom)
{
  if (this->workFunc != nullptr)
  {
    if (this->workFunc(rcvBuff, rcvBuffSize, txnBuff, txnBuffSize, txnBuffTotalBytesWritten, receivedFrom)
                  == MEventWorkItemResult::KEEP_CHAINING)
    {
      if (this->nextWorkItem != nullptr)
      {
        this->nextWorkItem->executeChain(rcvBuff, rcvBuffSize, txnBuff, txnBuffSize, txnBuffTotalBytesWritten, receivedFrom);
      }
    }
  }
}





moveOS::base::MIntegralDataEventWorkItem::MIntegralDataEventWorkItem(integral_data_handler_func workFunc)
{
  this->workFunc = workFunc;
  this->nextWorkItem = nullptr;
}

void moveOS::base::MIntegralDataEventWorkItem::executeSelf(uint16 data)
{
  if (this->workFunc != nullptr)
  {
    this->workFunc(data);
  }
}

void moveOS::base::MIntegralDataEventWorkItem::executeChain(uint16 data)
{
  if (this->workFunc != nullptr)
  {
    if (this->workFunc(data) == MEventWorkItemResult::KEEP_CHAINING)
    {
      if (this->nextWorkItem != nullptr)
      {
        this->nextWorkItem->executeChain(data);
      }
    }
  }
}

