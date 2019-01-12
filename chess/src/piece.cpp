enum class PieceType
{
    NONE,
    PAWN,   
    KNIGHT,
    BISHOP, 
    ROOK,
    QUEEN, 
    KING,  
    
};

enum class Freedom
{
    FULL,
    DIAGONAL,
    CROSS,
    HOOK,
    NONE
};

enum class Team 
{
    WHITE,
    BLACK,
    NONE
};

class Piece
{
  private:
    PieceType m_pieceType;
    Freedom m_freedom;
    Team m_team;
    int m_distance;

  public:
    // Default constructor
    Piece(
        PieceType pieceType = PieceType::NONE,
        Freedom freedom = Freedom::NONE,
        Team team = Team::NONE
    )
    {
        m_team = team;
        m_pieceType = pieceType;
        m_freedom = freedom;
        m_distance = calcDistance();
    }

    int calcDistance()
    {
        if (m_pieceType == PieceType::PAWN)
            return 1;
        else if (m_pieceType == PieceType::KNIGHT)
            return 3;
        else if (m_pieceType == PieceType::BISHOP)
            return 7;
        else if (m_pieceType == PieceType::ROOK)
            return 7;
        else if (m_pieceType == PieceType::QUEEN)
            return 7;
        else if (m_pieceType == PieceType::KING)
            return 1;
        else
            return 1;
    }

    int getDistance() { return m_distance; }

    const char* getTeam()
    {
        if (m_team == Team::BLACK)
            return "-B";
        else if (m_team == Team::WHITE)
            return "-W";
        else
            return "  ";
    }

    const char* getFreedom()
    {
        if (m_freedom == Freedom::FULL)
            return "Full";
        else if (m_freedom == Freedom::DIAGONAL)
            return "Diagonal";
        else if (m_freedom == Freedom::CROSS)
            return "Cross";
        else if (m_freedom == Freedom::HOOK)
            return "Hook";
        else
            return "Who knows!";
    }

    const char* getPieceType()
    { 
        if (m_pieceType == PieceType::PAWN) {
            if (m_team == Team::BLACK) {
                return "p";
            }
            else if (m_team == Team::WHITE) {
                return "P";
            }
        }
        else if (m_pieceType == PieceType::KNIGHT) {
            if (m_team == Team::BLACK) {
                return "n";
            }
            else if (m_team == Team::WHITE) {
                return "N";
            }
        }
        else if (m_pieceType == PieceType::BISHOP) {
            if (m_team == Team::BLACK) {
                return "b";
            }
            else if (m_team == Team::WHITE) {
                return "B";
            }
        }
        else if (m_pieceType == PieceType::ROOK) {
            if (m_team == Team::BLACK) {
                return "r";
            }
            else if (m_team == Team::WHITE) {
                return "R";
            }
        }
        else if (m_pieceType == PieceType::QUEEN) {
            if (m_team == Team::BLACK) {
                return "q";
            }
            else if (m_team == Team::WHITE) {
                return "Q";
            }
        }
        else if (m_pieceType == PieceType::KING) {
            if (m_team == Team::BLACK) {
                return "k";
            }
            else if (m_team == Team::WHITE) {
                return "K";
            }
        }
        else {
            return " ";
        }
    }
};
