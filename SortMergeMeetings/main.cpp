#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

  class Meeting
{
private:
        // number of 30 min blocks past 9:00 am
        unsigned int startTime_;
        unsigned int endTime_;

public:
    Meeting() :
        startTime_(0),
        endTime_(0)
    {
    }

    Meeting(unsigned int startTime, unsigned int endTime) :
        startTime_(startTime),
        endTime_(endTime)
    {
    }

    unsigned int getStartTime() const
    {
        return startTime_;
    }

    void setStartTime(unsigned int startTime)
    {
        startTime_ = startTime;
    }

    unsigned int getEndTime() const
    {
        return endTime_;
    }

    void setEndTime(unsigned int endTime)
    {
        endTime_ = endTime;
    }

    bool operator==(const Meeting& other) const
    {
        return
            startTime_ == other.startTime_
            && endTime_ == other.endTime_;
    }
};
bool CompareMeetings(const Meeting& firstMeeting, const Meeting& secondMeeting){
    return firstMeeting.getStartTime() < secondMeeting.getStartTime();
}

vector<Meeting> MergeMeetings(vector<Meeting> MeetingsToMerge){
        vector<Meeting> SortedMeanings(MeetingsToMerge);
        sort(SortedMeanings.begin(), SortedMeanings.end(), CompareMeetings);

        vector<Meeting> MergedMeetings;
        MergedMeetings.push_back(SortedMeanings.front());

        for(Meeting CurrentMeeting : SortedMeanings){
            Meeting& LastMerged = MergedMeetings.back();
            if(CurrentMeeting.getStartTime() <= LastMerged.getEndTime()){
                LastMerged.setEndTime(max(CurrentMeeting.getEndTime(), LastMerged.getEndTime()));
            }
            else{
                MergedMeetings.push_back(CurrentMeeting);
            }
        }
        return MergedMeetings;
}

int main()
{
    vector<Meeting> MeetingsToMerge = {Meeting(0, 1), Meeting(3, 5), Meeting(4, 8), Meeting(10, 12), Meeting(9, 10)};
    vector<Meeting> Merged = MergeMeetings(MeetingsToMerge);
    for(Meeting Current : Merged){
        cout << Current.getStartTime() << ", " << Current.getEndTime() << " | ";
    }
    return 0;
}
