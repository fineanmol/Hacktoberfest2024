class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long> roomAvailabilityTime(n, 0);
        vector<int> meetingCount(n, 0);
        sort(meetings.begin(), meetings.end());

        for (auto& meeting: meetings) {
            int start = meeting[0], end = meeting[1];
            long long minRoomAvailabilityTime = LLONG_MAX;
            int minAvailableTimeRoom = 0;
            bool foundUnusedRoom = false;

            for (int i = 0; i < n; i++) {
                if (roomAvailabilityTime[i] <= start) {
                    foundUnusedRoom = true;
                    meetingCount[i]++;
                    roomAvailabilityTime[i] = end;
                    break;
                }

                if (minRoomAvailabilityTime > roomAvailabilityTime[i]) {
                    minRoomAvailabilityTime = roomAvailabilityTime[i];
                    minAvailableTimeRoom = i;
                }
            }

            if (!foundUnusedRoom) {
                roomAvailabilityTime[minAvailableTimeRoom] += end - start;
                meetingCount[minAvailableTimeRoom]++;
            }
        }
        int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetingCount) {
                maxMeetingCount = meetingCount[i];
                maxMeetingCountRoom = i;
            }
        }
        return maxMeetingCountRoom;
    }
};