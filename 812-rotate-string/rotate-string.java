class Solution 
{
    public boolean isRotation(String s,String goal)
    {
        String temp = s+s;
        if(temp.contains(goal))
        {
            return true;
        }
        return false;
    }
    public boolean rotateString(String s, String goal) 
    {
        if(s.length() != goal.length()) return false;
        if(isRotation(s,goal))
        {
            return true;
        }    
        return false;
    }
}