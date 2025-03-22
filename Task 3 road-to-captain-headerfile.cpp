#ifndef ROAD_TO_CAPTAIN_H
#define ROAD_TO_CAPTAIN_H

#include <string>
#include <vector>
#include <map>
#include <memory>

using namespace std;

namespace RoadToCaptain {

// Forward declarations
class Player;
class LeadershipEvent;
class Choice;
class LeadershipImpact;
class CaptainProgression;
class CaptainPerk;
class Team;
class CoachRelationship;
class GamePerformance;
class CaptaincySystem;
class Interaction;

// Enumerations
enum class EventType {
    TEAM_CRISIS,
    MENTORING,
    MEDIA_INTERACTION,
    PRACTICE_LEADERSHIP,
    LOCKER_ROOM_SPEECH,
    COMMUNITY_SERVICE
};

enum class PerkType {
    TEAM_BOOST,
    INDIVIDUAL_STAT,
    UNLOCK_DIALOGUE,
    TEAM_STRATEGY,
    SPECIAL_ABILITY
};

enum class CaptainType {
    INSPIRATIONAL,
    VOCAL,
    QUIET_LEADER,
    STRATEGIC,
    EMOTIONAL
};

enum class Position {
    QUARTERBACK,
    RUNNING_BACK,
    WIDE_RECEIVER,
    TIGHT_END,
    OFFENSIVE_LINE,
    DEFENSIVE_LINE,
    LINEBACKER,
    CORNERBACK,
    SAFETY,
    KICKER,
    PUNTER
};

// Class definitions
class Player {
private:
    int playerId;
    string name;
    Position position;
    int overallRating;
    int leadershipScore;
    bool isCaptain;
    CaptainType captainType;
    shared_ptr<CaptainProgression> progression;
    shared_ptr<CoachRelationship> coachRelationship;
    vector<shared_ptr<GamePerformance>> performances;

public:
    // Constructor
    Player(int id, const string& playerName, Position pos, int rating);
    
    // Getters
    int getPlayerId() const;
    string getName() const;
    Position getPosition() const;
    int getOverallRating() const;
    int getLeadershipScore() const;
    bool getIsCaptain() const;
    CaptainType getCaptainType() const;
    shared_ptr<CaptainProgression> getProgression() const;
    shared_ptr<CoachRelationship> getCoachRelationship() const;
    
    // Setters
    void setName(const string& playerName);
    void setPosition(Position pos);
    void setOverallRating(int rating);
    void setLeadershipScore(int score);
    void setIsCaptain(bool captain);
    void setCaptainType(CaptainType type);
    
    // Methods
    void performGameAction();
    int makeLeadershipChoice(const LeadershipEvent& event, int choiceIndex);
    void increaseStat(const string& statName, int amount);
    bool checkCaptainEligibility() const;
    void addGamePerformance(const shared_ptr<GamePerformance>& performance);
};

class LeadershipEvent {
private:
    int eventId;
    string description;
    EventType type;
    int difficultyLevel;
    vector<shared_ptr<Choice>> choices;

public:
    // Constructor
    LeadershipEvent(int id, const string& desc, EventType eventType, int difficulty);
    
    // Getters
    int getEventId() const;
    string getDescription() const;
    EventType getType() const;
    int getDifficultyLevel() const;
    vector<shared_ptr<Choice>> getChoices() const;
    
    // Setters
    void setDescription(const string& desc);
    void setType(EventType eventType);
    void setDifficultyLevel(int difficulty);
    
    // Methods
    void triggerEvent(Player& player);
    int evaluatePlayerChoice(int choiceIndex);
    void applyOutcome(Player& player, int choiceIndex);
    void addChoice(const shared_ptr<Choice>& choice);
};

class Choice {
private:
    int choiceId;
    string description;
    shared_ptr<LeadershipImpact> impact;

public:
    // Constructor
    Choice(int id, const string& desc, const shared_ptr<LeadershipImpact>& choiceImpact);
    
    // Getters
    int getChoiceId() const;
    string getDescription() const;
    shared_ptr<LeadershipImpact> getImpact() const;
    
    // Setters
    void setDescription(const string& desc);
    void setImpact(const shared_ptr<LeadershipImpact>& choiceImpact);
    
    // Methods
    int selectChoice(Player& player);
};

class LeadershipImpact {
private:
    int teamMoraleEffect;
    int coachRelationshipEffect;
    int teammateTrustEffect;
    int leadershipPointsGained;

public:
    // Constructor
    LeadershipImpact(int moraleEffect, int relationshipEffect, int trustEffect, int points);
    
    // Getters
    int getTeamMoraleEffect() const;
    int getCoachRelationshipEffect() const;
    int getTeammateTrustEffect() const;
    int getLeadershipPointsGained() const;
    
    // Setters
    void setTeamMoraleEffect(int effect);
    void setCoachRelationshipEffect(int effect);
    void setTeammateTrustEffect(int effect);
    void setLeadershipPointsGained(int points);
    
    // Methods
    void applyImpact(Player& player, Team& team);
};

class CaptainProgression {
private:
    int currentLevel;
    int pointsToNextLevel;
    vector<shared_ptr<CaptainPerk>> unlockedPerks;
    CaptainType leadershipStyle;
    int totalPointsEarned;

public:
    // Constructor
    CaptainProgression(CaptainType style = CaptainType::INSPIRATIONAL);
    
    // Getters
    int getCurrentLevel() const;
    int getPointsToNextLevel() const;
    vector<shared_ptr<CaptainPerk>> getUnlockedPerks() const;
    CaptainType getLeadershipStyle() const;
    int getTotalPointsEarned() const;
    
    // Setters
    void setLeadershipStyle(CaptainType style);
    
    // Methods
    bool levelUp();
    void unlockPerk(const shared_ptr<CaptainPerk>& perk);
    void trackProgress(int pointsGained);
    void addPoints(int points);
    bool isPerkUnlocked(int perkId) const;
};

class CaptainPerk {
private:
    int perkId;
    string name;
    string description;
    PerkType type;
    int unlockThreshold;
    bool isActive;

public:
    // Constructor
    CaptainPerk(int id, const string& perkName, const string& desc, 
                PerkType perkType, int threshold);
    
    // Getters
    int getPerkId() const;
    string getName() const;
    string getDescription() const;
    PerkType getType() const;
    int getUnlockThreshold() const;
    bool getIsActive() const;
    
    // Setters
    void setName(const string& perkName);
    void setDescription(const string& desc);
    void setType(PerkType perkType);
    void setUnlockThreshold(int threshold);
    void setIsActive(bool active);
    
    // Methods
    void activatePerk(Player& player);
    void applyEffect(Player& player, Team& team);
};

class Team {
private:
    int teamId;
    string name;
    vector<shared_ptr<Player>> roster;
    int teamMorale;
    int teamChemistry;
    shared_ptr<Player> captain;

public:
    // Constructor
    Team(int id, const string& teamName);
    
    // Getters
    int getTeamId() const;
    string getName() const;
    vector<shared_ptr<Player>> getRoster() const;
    int getTeamMorale() const;
    int getTeamChemistry() const;
    shared_ptr<Player> getCaptain() const;
    
    // Setters
    void setName(const string& teamName);
    void setTeamMorale(int morale);
    void setTeamChemistry(int chemistry);
    
    // Methods
    bool assignCaptain(const shared_ptr<Player>& player);
    void updateTeamStats();
    void applyMoraleBoost(int amount);
    void addPlayer(const shared_ptr<Player>& player);
    void removePlayer(int playerId);
    shared_ptr<Player> getPlayer(int playerId) const;
};

class Interaction {
private:
    int interactionId;
    string description;
    int relationshipImpact;
    string date;

public:
    // Constructor
    Interaction(int id, const string& desc, int impact, const string& interactionDate);
    
    // Getters
    int getInteractionId() const;
    string getDescription() const;
    int getRelationshipImpact() const;
    string getDate() const;
};

class CoachRelationship {
private:
    int relationshipLevel;
    int trust;
    vector<Interaction> pastInteractions;

public:
    // Constructor
    CoachRelationship();
    
    // Getters
    int getRelationshipLevel() const;
    int getTrust() const;
    vector<Interaction> getPastInteractions() const;
    
    // Setters
    void setRelationshipLevel(int level);
    void setTrust(int trustLevel);
    
    // Methods
    void improveRelationship(int amount);
    void evaluatePerformance(const GamePerformance& performance);
    bool considerForCaptaincy(const Player& player) const;
    void addInteraction(const Interaction& interaction);
};

class GamePerformance {
private:
    int gameId;
    map<string, int> statistics;
    int leadershipMomentCount;
    bool clutchPlay;
    int leadershipPointsEarned;

public:
    // Constructor
    GamePerformance(int id);
    
    // Getters
    int getGameId() const;
    map<string, int> getStatistics() const;
    int getLeadershipMomentCount() const;
    bool getClutchPlay() const;
    int getLeadershipPointsEarned() const;
    
    // Setters
    void setLeadershipMomentCount(int count);
    void setClutchPlay(bool clutch);
    void setLeadershipPointsEarned(int points);
    
    // Methods
    void recordStats(const string& statName, int value);
    int calculateLeadershipImpact();
    void highlightLeadershipMoments();
    int getStat(const string& statName) const;
};

class CaptaincySystem {
private:
    shared_ptr<Player> playerCharacter;
    shared_ptr<Team> currentTeam;
    shared_ptr<CoachRelationship> coachRelationship;
    shared_ptr<CaptainProgression> progression;
    vector<shared_ptr<LeadershipEvent>> availableEvents;
    
    // Private methods
    void initializeEvents();
    void initializePerks();

public:
    // Constructor
    CaptaincySystem(const shared_ptr<Player>& player, const shared_ptr<Team>& team);
    
    // Getters
    shared_ptr<Player> getPlayerCharacter() const;
    shared_ptr<Team> getCurrentTeam() const;
    vector<shared_ptr<LeadershipEvent>> getAvailableEvents() const;
    
    // Methods
    bool evaluateCaptaincyEligibility();
    shared_ptr<LeadershipEvent> triggerRandomEvent();
    void trackProgressionMilestones();
    bool awardCaptaincy();
    void registerGamePerformance(const shared_ptr<GamePerformance>& performance);
    void addEvent(const shared_ptr<LeadershipEvent>& event);
};

} // namespace RoadToCaptain

#endif // ROAD_TO_CAPTAIN_H
