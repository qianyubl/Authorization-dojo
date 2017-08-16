#pragma once

class IResource
{
public:
		virtual void read()=0;
		virtual void write()=0;
};