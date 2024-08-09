void StTime()
{
  BaseTime0 = millis();
  Time0 = 0;
  
  }
long ReadTime()
{
  Time0 = millis() - BaseTime0;
  return (Time0);
  }

  
